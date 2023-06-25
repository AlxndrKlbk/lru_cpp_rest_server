#include <drogon/drogon.h>
#include <iostream>

// internal
#include "lru_cache/lru_cache.hpp"

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
    LRUCache* instance = LRUCache::instance( capacity );
    LRUCache* instance2 = LRUCache::instance( capacity );

    cout << &( *instance ) << endl;
    cout << &( *instance2 ) << endl;

    app()
        // Регистрируем обработчик indexHandler
        // для запроса
        // GET /
        .registerHandler("/", &indexHandler, {Get})
        .addListener("0.0.0.0",8080)
        .setThreadNum( threads_count )
        .run();

    return EXIT_SUCCESS;
}

void indexHandler(const HttpRequestPtr &request, Callback &&callback) {
    // Формируем JSON-объект
    Json::Value jsonBody;
    jsonBody["message"] = "Hello, world";

    // Формируем и отправляем ответ с JSON-объектом
    auto response = HttpResponse::newHttpJsonResponse(jsonBody);
    callback(response);
}
