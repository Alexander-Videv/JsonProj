#include "Array.hpp"

bool Array::contains(std::string &value) const
{
    bool contains = false;
    for (size_t i = 0; i < objArray.size(); i++)
    {
        if (objArray[i].contains(value))
            contains = true;
    }
    return contains;
}

std::vector<Value *> Array::search(std::string &sKey) const
{
    std::vector<Value *> values;
    for (size_t i = 0; i < objArray.size(); i++)
    {
        std::vector<Value *> toBeAdded = objArray[i].search(sKey);
        for (size_t j = 0; j < toBeAdded.size(); j++)
        {
            values.push_back(toBeAdded.at(j));
        }
    }
    return values;
}

void Array::set(std::string &path, std::string &value)
{
    std::string valueCopy = value;
    for (size_t i = 0; i < objArray.size(); i++)
    {
        valueCopy = value;
        objArray[i].set(path, valueCopy);
    }
}

Array::Array(std::string &text)
{
    this->objArray.clear();
    text.erase(0, 1);
    text.erase(text.length() - 1, 1);
    while (!text.empty())
    {
        std::string buffer;
        buffer = text.substr(0, text.find(",{"));
        if (buffer.empty())
            buffer = text;
        text.erase(0, buffer.length() + 1);
        Object obj(buffer);
        this->objArray.push_back(obj);
    }
    setType(JsonType::Array);
}