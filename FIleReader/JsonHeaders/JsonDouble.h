#include "JsonValue.h"

#ifndef JSON_DOUBLE_H
#define JSON_DOUBLE_H

class JsonDouble : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    double value;

public:
    JsonDouble();
    ~JsonDouble();
};

#endif