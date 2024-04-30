#include "JsonValue.h"

class JsonInteger : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    int value;

public:
    JsonInteger();
    ~JsonInteger();
};