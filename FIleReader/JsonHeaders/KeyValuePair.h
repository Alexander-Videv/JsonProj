
#ifndef KEY_VALUE_PAIR_H
#define KEY_VALUE_PAR_H

struct KeyValuePair
{
public:
    std::string key;
    JsonValue *value;

public:
    void print(std::ostream &os) const;
    void setKey(std::string &key);
    void setValue(JsonValue *value);

    KeyValuePair(std::string &key, JsonValue *value);
};

#endif