#ifndef JSON_VALUE_H
#define JSON_VALUE_H

class JsonValue
{
protected:
public:
    virtual ~JsonValue(){};
    virtual void print(std::ostream &os) const = 0;
    virtual JsonValue *clone() const = 0;
};

#endif