#include "JsonValue.h"
#include <string>
#include <string.h>
#include <vector>

#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

class JsonObject : public JsonValue
{
private:
    struct KeyValuePair
    {
    public:
        std::string key;
        JsonValue *value;
        void print(std::ostream &os)
        {
            os << key;
            // value->print(os);
        };
    };
    // JsonObject();
    std::vector<KeyValuePair> value;

public:
    JsonObject(std::string &key, std::string &value);
    ~JsonObject() = default;
    void print(std::ostream &os);
};

#endif