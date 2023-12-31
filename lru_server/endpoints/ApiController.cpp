#include "ApiController.hpp"
#include "lru_cache/lru_cache.hpp"
#include <iostream>
// Add definition of your processing function here


HttpResponsePtr makeSuccessResponse()
{
    Json::Value json;
    json["ok"] = true;
    auto resp = HttpResponse::newHttpJsonResponse(json);
    return resp;
}

HttpResponsePtr makeFailedResponse()
{
    Json::Value json;
    json["ok"] = false;
    auto resp = HttpResponse::newHttpJsonResponse(json);
    resp->setStatusCode(k500InternalServerError);
    return resp;
}

void ApiController::get( const HttpRequestPtr& req, Callback &&callback )
{
    std::shared_ptr< LRUCache > cache = LRUCache::instance( );
    try
    {
        auto jsonPtr = req->getJsonObject();
        Json::Value res;
        res["value"] = cache->get( (*jsonPtr)["key"].asLargestInt() );

        callback( HttpResponse::newHttpJsonResponse( std::move( res ) ) );
    }
    catch( ... )
    {
        callback( makeFailedResponse() );
    }
}

void ApiController::post(const HttpRequestPtr& req, Callback &&callback ) const
{
    std::shared_ptr< LRUCache > cache = LRUCache::instance( );
    try
    {
        auto jsonPtr = req->getJsonObject();
        Json::Value res;

        cache->put( (*jsonPtr)["key"].asLargestInt(),
                         (*jsonPtr)["value"].asLargestInt() );
        callback( makeSuccessResponse() );
    }
    catch( ... )
    {
        callback( makeFailedResponse() );
    }
}
