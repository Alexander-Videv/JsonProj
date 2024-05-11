#include "JsonValue.h"
#include <string>

#ifndef JSON_DATE_H
#define JSON_DATE_H

class JsonDate : public JsonValue
{
private:
    std::string value;

public:
    JsonDate();
    ~JsonDate();
    void print(std::ostream &os) const override;
    JsonValue *clone() const override;
};

#endif