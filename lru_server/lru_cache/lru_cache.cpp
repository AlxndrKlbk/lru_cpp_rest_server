
// internal
#include "lru_cache/lru_cache.hpp"

mutex mtx;
LRUCache* volatile LRUCache::pInstance = 0;

LRUCache* const LRUCache::instance( int capacity ){
    if (pInstance == 0) {
        mtx.lock();
        if (pInstance == 0) {
            LRUCache* volatile temp = new LRUCache( capacity );
            pInstance = temp;
        }
        mtx.unlock();
    }

    return pInstance;
}

bool LRUCache::get( int key )
{
    auto it = map.find(key);
    if (it == map.end()) {
        return false;
    }
    cache.splice(cache.end(), cache, it->second);
    return true;
}

void LRUCache::refer( int key )
{
    if (get(key)) {
        return;
    }
    put(key);
}

void LRUCache::display()
{
    for (auto it = cache.rbegin(); it != cache.rend(); ++it) {
        cout << *it << " ";
    }
}

void LRUCache::put( int key ) {
    if (cache.size() == capacity) {
        int first_key = cache.front();
        cache.pop_front();
        map.erase(first_key);
    }
    cache.push_back(key);
    map[key] = --cache.end();
}
