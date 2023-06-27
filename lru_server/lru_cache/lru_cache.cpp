// internal
#include "lru_cache/lru_cache.hpp"

mutex mtx;
std::shared_ptr< LRUCache > LRUCache::mInstancePtr = nullptr;

void LRUCache::setMap(const unordered_map<Int64, list<Int64>::iterator> &newMap)
{
    mMap = newMap;
}

std::shared_ptr< LRUCache > const LRUCache::instance( Int64 capacity ){
    // ToDo it is not null before ini
    if ( mInstancePtr == nullptr ) {
        mtx.lock();
        if (mInstancePtr == 0) {
            mInstancePtr = std::shared_ptr< LRUCache >( new LRUCache( capacity ) );
        }
        mtx.unlock();
    }

    return mInstancePtr;
}

Int64 LRUCache::get( const Int64& key )
{
    auto it = mMap.find(key);
    if (it == mMap.end()) {
        return -1;
    }
    mCache.splice(mCache.end(), mCache, it->second);
    return *( it->second );
}

void LRUCache::refer( const Int64& key, const Int64& value )
{
    if ( get( key ) ) {
        return;
    }
    put( key, value );
}

void LRUCache::display()
{
    for (auto it = mCache.rbegin(); it != mCache.rend(); ++it) {
        cout << *it << " ";
    }
}

void LRUCache::put( const Int64& key, const Int64& value ) {
    if (mCache.size() == mCapacity) {
        Int64 first_key = mCache.front();
        mCache.pop_front();
        mMap.erase(first_key);
    }
    mCache.push_back(value);
    mMap[key] = --mCache.end();
}
