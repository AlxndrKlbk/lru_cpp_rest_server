#include "endpoints/endpoints.hpp"

using namespace drogon;

void indexHandler(const HttpRequestPtr &request, Callback &&callback) {
    Json::Value jsonBody;
    jsonBody["message"] = "Hello, world";

    auto response = HttpResponse::newHttpJsonResponse(jsonBody);
    callback(response);
}
