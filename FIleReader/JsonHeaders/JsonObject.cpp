#include "JsonObject.h"

// whole cpp file need writing once i figure out some of the other logic of the header file
// which will come after i figure out the splitting of information
// this should be an easy file once i figure those things out

void JsonObject::print(std::ostream &os)
{

    for (size_t i = 0; i < value.size(); i++)
    {
        value[i].print(os);
    }
}

JsonObject::JsonObject(std::string &key, std::string &value) : JsonValue(TYPE::OBJECT)
{
    this->type = TYPE::OBJECT;
    KeyValuePair object;
    this->value.push_back(object);
    this->value[0].key = key;
}
