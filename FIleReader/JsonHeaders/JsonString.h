#include "JsonValue.h"
#include <string>

class JsonString : public JsonValue
{
private:
    std::string value;

public:
    JsonString();  // all of the constructors of these child classes should call the parametricized constructor
    ~JsonString(); // of the JsonValue class using the right type
};