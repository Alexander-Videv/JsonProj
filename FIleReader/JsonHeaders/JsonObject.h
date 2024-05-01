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
        void print(std::ostream &os);
    };
    JsonValue(TYPE::OBJECT);
    std::vector<KeyValuePair> value;

public:
    JsonObject(std::string &str);
    ~JsonObject();
    void print(std::ostream &os);
};