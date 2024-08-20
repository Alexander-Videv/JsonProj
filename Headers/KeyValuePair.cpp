#include "KeyValuePair.hpp"

KeyValuePair::KeyValuePair(Value *ptr, std::string &key)
{
    setKey(key);
    setValue(ptr);
}

void KeyValuePair::print(std::ostream &output) const
{
    output << key << ":";
    value->print(output);
}

void KeyValuePair::saveprint(std::ostream &output) const
{
    output << "\"" << key << "\"" << ":";
    if (value->getType() != JsonType::Object && value->getType() != JsonType::Array)
    {
        output << "\"";
        value->saveprint(output);
        output << "\"";
    }
    else
        value->saveprint(output);
}

void KeyValuePair::setKey(std::string &key)
{
    this->key = key;
}

void KeyValuePair::setValue(Value &json)
{
    this->value = &json;
}

void KeyValuePair::setValue(Value *json)
{
    value = json;
}

std::string &KeyValuePair::getKey()
{
    return this->key;
}

Value *KeyValuePair::getJson()
{
    return value;
}
