#ifndef JSON_VALUE_H
#define JSON_VALUE_H

class JsonValue
{
protected:
    enum class TYPE
    {
        STRING,
        INTEGER,
        DATE,
        ARRAY,
        OBJECT
    };
    TYPE type;

public:
    // JsonValue() = delete;
    JsonValue(TYPE type) { this->type = type; };
    virtual ~JsonValue() = default;
    virtual void print(std::ostream &os) = 0;
};

#endif