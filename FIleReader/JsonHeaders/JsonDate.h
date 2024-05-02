#include "JsonValue.h"
#include <string>

#ifndef JSON_DATE_H
#define JSON_DATE_H

class JsonDate : public JsonValue
{
private:
    JsonValue(TYPE::DATE);
    std::string value;

public:
    JsonDate();
    ~JsonDate();
};

#endif