#pragma once

#include <drogon/HttpController.h>

// internal
#include "forwards.hpp"


class ApiController : public drogon::HttpController<ApiController>
{
  public:
    METHOD_LIST_BEGIN

    METHOD_ADD(ApiController::get, "/get", Get);
    METHOD_ADD(ApiController::post, "/post", Post);

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void get(const HttpRequestPtr& req, Callback &&callback);
    void post(const HttpRequestPtr& req, Callback &&callback ) const;
};
