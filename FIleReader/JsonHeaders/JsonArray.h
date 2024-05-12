#include "JsonValue.h"
#include <vector>

#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

class JsonArray : public JsonValue
{
private:
    std::vector<JsonValue *> array;

public:
    JsonArray(std::string &key, std::string &value);
    ~JsonArray();
    void print(std::ostream &os) const override;
    JsonValue *clone() const override;
};

#endif