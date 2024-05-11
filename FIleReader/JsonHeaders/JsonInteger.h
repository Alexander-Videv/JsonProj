#include "JsonValue.h"

#ifndef JSON_INTEGER_H
#define JSON_INTEGER_H

class JsonInteger : public JsonValue
{
private:
    int value;

public:
    JsonInteger();
    ~JsonInteger();
    void print(std::ostream &os) const override;
    JsonValue *clone() const override;
};

#endif