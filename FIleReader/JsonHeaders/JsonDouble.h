#include "JsonValue.h"

class JsonDouble : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    double value;

public:
    JsonDouble();
    ~JsonDouble();
};