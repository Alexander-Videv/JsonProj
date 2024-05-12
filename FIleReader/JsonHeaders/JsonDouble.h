#include "JsonValue.h"

#ifndef JSON_DOUBLE_H
#define JSON_DOUBLE_H

class JsonDouble : public JsonValue
{
private:
    double value;

public:
    JsonDouble(std::string &key, std::string &value);
    ~JsonDouble();
    void print(std::ostream &os) const override;
    JsonValue *clone() const override;
};

#endif