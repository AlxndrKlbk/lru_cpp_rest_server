#pragma once

#include <mutex>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
using std::mutex;

class LRUCache {
private:
    int capacity;
    list< int > cache;
    unordered_map< int, list< int >::iterator > map;
    static LRUCache* volatile pInstance;

    // constructors : Don't Implement.
    LRUCache( int capacity ): capacity( capacity ){};
    LRUCache(LRUCache const&);
    void operator=(LRUCache const&);

public:
    static LRUCache* const instance( int capacity );

    /**
     * @brief returns false if key is not present in cache.
     * @brief Else it moves the key to front by first removing it and then adding it, and returns true.
     * @param key
     * @return
     */
    bool get( int key );

    /**
     * @brief refer
     * @param key
     */
    void refer( int key );

    /**
     * @brief display contents of cache in Reverse Order
     */
    void display();

    /**
     * @brief put value to cache
     * @param key
     */
    void put( int key );
};
