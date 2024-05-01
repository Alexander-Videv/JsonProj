#include "JsonValue.h"
#include <string>

class JsonDate : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    std::string value;

public:
    JsonDate();
    ~JsonDate();
};