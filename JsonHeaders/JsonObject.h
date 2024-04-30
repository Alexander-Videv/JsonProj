#include "JsonValue.h"
#include <string>
#include <vector>

class JsonObject : public JsonValue
{
private:
    struct KeyValuePair
    {
    private:
        std::string key;
        JsonValue *value;
    };
    JsonValue(TYPE::OBJECT);
    std::vector<KeyValuePair> value;

public:
    JsonObject();
    ~JsonObject();
};