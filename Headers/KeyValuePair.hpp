#include "Value.hpp"
#include <string>

#ifndef KEY__VALUE__PAIR_HPP
#define KEY__VALUE__PAIR_HPP

struct KeyValuePair
{
    void print(std::ostream &output) const;

    void setKey(std::string &key);
    void setValue(Value &json);

    std::string &getKey();
    Value *getJson();

    std::string key;
    Value *value;
};

#endif