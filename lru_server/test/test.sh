#!/bin/bash

delimiter="\n----------\n"

echo -e "test should be run on server with capacity = 2"

echo -e $delimiter "post {"key":1, "value": 1}"
curl -XPOST http://0.0.0.0:8080/ApiController/post -i -H 'content-type: application/json' -d '{"key":1, "value": 1}'
echo -e " should be 'ok'"

echo -e $delimiter "post {"key":2, "value": 2}"
curl -XPOST http://0.0.0.0:8080/ApiController/post -i -H 'content-type: application/json' -d '{"key":2, "value": 2}'
echo -e " should be 'ok'"

echo -e $delimiter "get {"key":1}"
curl -XGET http://0.0.0.0:8080/ApiController/get -i -H 'content-type: application/json' -d '{"key":1}'
echo -e " should be 1"

echo -e $delimiter "post {"key":3, "value": 3}" 
curl -XPOST http://0.0.0.0:8080/ApiController/post -i -H 'content-type: application/json' -d '{"key":3, "value": 3}'
echo -e " should be 'ok'"

echo -e $delimiter "get {"key":2}"
curl -XGET http://0.0.0.0:8080/ApiController/get -i -H 'content-type: application/json' -d '{"key":2}'
echo -e " should be -1"

echo -e $delimiter "post {"key":3, "value": 3}"
curl -XPOST http://0.0.0.0:8080/ApiController/post -i -H 'content-type: application/json' -d '{"key":4, "value": 4}'
echo -e " should be 'ok'"

echo -e $delimiter "get {"key":1}"
curl -XGET http://0.0.0.0:8080/ApiController/get -i -H 'content-type: application/json' -d '{"key":1}'
echo -e " should be -1"

echo -e $delimiter "get {"key":3}"
curl -XGET http://0.0.0.0:8080/ApiController/get -i -H 'content-type: application/json' -d '{"key":3}'
echo -e " should be 3"

echo -e $delimiter "get {"key":4}"
curl -XGET http://0.0.0.0:8080/ApiController/get -i -H 'content-type: application/json' -d '{"key":4}'
echo -e " should be 4"


echo -e $delimiter "post {"key":3, "value": 3}"
curl -XPOST http://0.0.0.0:8080/ApiController/post -i -H 'content-type: application/json' -d '{"key":4, "value": 4}'
echo -e " should be 'ok'"


echo -e $delimiter "post {"key":3, "value": 3}"
curl -XPOST http://0.0.0.0:8080/ApiController/post -i -H 'content-type: application/json' -d '{"key":4, "value": 4}'
echo -e " should be 'ok'"

echo -e $delimiter "post {"key":3, "value": 3}"
curl -XPOST http://0.0.0.0:8080/ApiController/post -i -H 'content-type: application/json' -d '{"key":4, "value": 4}'
echo -e " should be 'ok'"

echo -e $delimiter "get {"key":3}"
curl -XGET http://0.0.0.0:8080/ApiController/get -i -H 'content-type: application/json' -d '{"key":3}'
echo -e " should be 3"

echo -e $delimiter "get {"key":4}"
curl -XGET http://0.0.0.0:8080/ApiController/get -i -H 'content-type: application/json' -d '{"key":4}'
echo -e " should be 4"
