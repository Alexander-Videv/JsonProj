#include "JsonValue.h"
#include "KeyValuePair.h"
#include <string>
#include <string.h>
#include <vector>

#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

class JsonObject : public JsonValue
{
private:
    std::string key;
    std::vector<KeyValuePair> value;

public:
    JsonObject(std::string &key, std::string &value);
    ~JsonObject() = default;
    void print(std::ostream &os) const override;
    JsonValue *clone() const override;
    // JsonValue *JsonObjectFactory(TYPE type, std::string &key, std::string &value);
    // TYPE parse(std::string &value);

    void add();
};

#endif