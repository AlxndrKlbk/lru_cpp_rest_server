#include <drogon/drogon.h>
#include <iostream>

// internal
#include "lru_cache/lru_cache.hpp"
#include "endpoints/endpoints.hpp"

using namespace drogon;

typedef std::function<void(const HttpResponsePtr &)> Callback;

void indexHandler(const HttpRequestPtr &request, Callback &&callback);

int main( int argc, char** argv ) {

    int capacity, threads_count;
    if( argc == 3)
    {
        capacity = atoi( argv[1] );
        threads_count = atoi( argv[2] );
    }
    else
    {
        cerr << "Error: launch without capacity and threads param" << endl;
        return 1;
    }
    auto instance = LRUCache::instance( capacity );
    auto instance2 = LRUCache::instance( capacity );

    cout << &( *instance ) << endl;
    cout << &( *instance2 ) << endl;

    app()
        .registerHandler("/", &indexHandler, {Get})
        .setThreadNum( threads_count )
        .loadConfigFile("./config.json")
        .run();

    return EXIT_SUCCESS;
}
