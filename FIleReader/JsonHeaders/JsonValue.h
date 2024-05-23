#ifndef JSON_VALUE_H
#define JSON_VALUE_H

#include <iostream>

class JsonValue
{
// protected:
public:
    virtual ~JsonValue() = default;
    virtual void print(std::ostream &os) const = 0;
    // virtual JsonValue *clone(JsonValue const &other) const /*= 0*/;
};

#endif