#include "JsonValue.h"
#include <string>

#ifndef JSON_STRING_H
#define JSON_STRING_H

class JsonString : public JsonValue
{
private:
    std::string value;

public:
    JsonString();  // all of the constructors of these child classes should call the parametricized constructor
    ~JsonString(); // of the JsonValue class using the right type
    JsonValue *clone() const override;
    void print(std::ostream &os) const override;
};

#endif