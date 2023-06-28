#pragma once

#include <memory>
#include <mutex>
#include <iostream>
#include <list>
#include <unordered_map>

// internal
#include "forwards.hpp"

using namespace std;
using std::mutex;

class LRUCache {
private:
    Int64 mCapacity;
    list< Int64 > mCache;
    unordered_map< Int64, list< Int64 >::iterator > mMap;
    static std::shared_ptr< LRUCache > mInstancePtr;

    // constructors : Don't Implement.
    LRUCache( Int64 capacity ): mCapacity( capacity ){};
    LRUCache(LRUCache const&);
    void operator=(LRUCache const&);

public:
    static std::shared_ptr< LRUCache > const instance( Int64 capacity = 0 );

    /**
     * @brief returns false if key is not present in cache.
     * @brief Else it moves the key to front by first removing it and then adding it, and returns true.
     * @param key
     * @return
     */
    Int64 get( const Int64& key );

    /**
     * @brief refer
     * @param key
     */
    void refer( const Int64& key, const Int64& value );

    /**
     * @brief display contents of cache in Reverse Order
     */
    void display();

    /**
     * @brief put value to cache
     * @param key
     */
    void put( const Int64& key, const Int64& value );
    void setMap(const unordered_map<Int64, list<Int64>::iterator> &newMap);
};
