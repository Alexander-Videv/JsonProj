#include "Value.hpp"
#include <string>

#ifndef KEY__VALUE__PAIR_HPP
#define KEY__VALUE__PAIR_HPP

struct KeyValuePair
{

    bool isEmpty() const { return value->isEmpty(); };
    void print(std::ostream &output) const;
    void saveprint(std::ostream &output) const;

    void setKey(std::string &key);
    void setValue(Value &json);
    void setValue(Value *json);

    std::string getKey() const;
    Value *getJson() const;

    std::string key;
    Value *value;

    KeyValuePair() = default;
    KeyValuePair(Value *ptr, std::string &key);
};

#endif