#include "KeyValuePair.h"

void KeyValuePair::print(std::ostream &os) const
{
    os << "key:" << this->key << " value:" << this->value;
}

KeyValuePair::KeyValuePair(std::string &key, JsonValue *value)
{
    this->key = key;
    this->value = value;
}
