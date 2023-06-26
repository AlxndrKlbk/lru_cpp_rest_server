#include "ApiController.hpp"
#include "lru_cache/lru_cache.hpp"

// Add definition of your processing function here

auto cache_inst = LRUCache::instance( 0 );

void ApiController::get( const HttpRequestPtr& req, Callback &&callback )
{
    auto jsonPtr = req->getJsonObject();
    Json::Value res;
    res["value"] = cache_inst->get( (*jsonPtr)["key"].asLargestInt() );

    callback( HttpResponse::newHttpJsonResponse( std::move( res ) ) );
}

void ApiController::post(const HttpRequestPtr& req, Callback &&callback ) const
{

}
