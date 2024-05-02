#include "JsonValue.h"

#ifndef JSON_INTEGER_H
#define JSON_INTEGER_H

class JsonInteger : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    int value;

public:
    JsonInteger();
    ~JsonInteger();
};

#endif