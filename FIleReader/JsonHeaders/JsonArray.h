#include "JsonValue.h"
#include <vector>

class JsonArray : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    std::vector<JsonValue *> array;

public:
    JsonArray();
    ~JsonArray();
};