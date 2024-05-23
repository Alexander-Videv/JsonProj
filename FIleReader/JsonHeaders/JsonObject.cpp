// #include "JsonObject.h"
#include "JsonObjectFunction.hpp"
#include "JsonObject.h"

void JsonObject::print(std::ostream &os) const
{
    for (size_t i = 0; i < value.size(); i++)
    {
        value[i].print(os);
    }
}

JsonObject::JsonObject(std::string &key, std::string &value) : JsonValue()
{
    if (key.empty())
    {
        this->key = nullptr;
    }
    else
    {
        this->key = key;
    }

    this->value.push_back(KeyValuePair(key, JsonObjectFactory(parse(value), key, value)));
}

JsonObject::JsonObject(std::istream &input)
{
    std::string newLine;

    while (newLine != '}')
    {
        std::getline(input, newLine);
        std::cout << newLine;
    }
}
// void JsonObject::add()
// {
//     // if (this->value)
//     // {
//     //     /* code */
//     // }
// }
