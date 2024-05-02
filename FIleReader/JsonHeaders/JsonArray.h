#include "JsonValue.h"
#include <vector>

#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

class JsonArray : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    std::vector<JsonValue *> array;

public:
    JsonArray();
    ~JsonArray();
};

#endif