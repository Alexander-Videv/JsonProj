#include "KeyValuePair.hpp"

void KeyValuePair::print(std::ostream &output) const
{
    output << key << ":";
    value->print(output);
}

void KeyValuePair::setKey(std::string &key)
{
    this->key = key;
}

void KeyValuePair::setValue(Value &json)
{
    this->value = &json;
}

std::string &KeyValuePair::getKey()
{
    return this->key;
}

Value *KeyValuePair::getJson()
{
    return value;
}
