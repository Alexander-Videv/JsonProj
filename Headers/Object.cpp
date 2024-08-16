#include "Object.hpp"
#include "String.hpp"
#include "Array.hpp"

int digitCount(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

KeyValuePair Object::parse(std::string &text)
{
    KeyValuePair pair;
    if (text[0] == '{' && text[text.length() - 1] == '}')
    {
        text.erase(0, 1);
        text.erase(text.find_last_of("}"), 1);
    }

    int pos = 0;
    std::string buffer;
    if (text.find(":") > 0)
    {
        pos = text.find(":");
        buffer = text.substr(0, pos);
        text.erase(0, pos + 1);
    }

    pair.setKey(buffer);
    Value *ptr = readValue(text);
    pair.setValue(*ptr);
    if (!text.empty())
        jsonArray.push_back(parse(text));

    return pair;
}

void Object::print(std::ostream &output) const
{

    for (int i = jsonArray.size() - 1; i >= 0; i--)
    {
        jsonArray[i].print(output);
        output << ' ';
    }
}

Value *Object::readValue(std::string &text)
{
    std::string buffer;
    int nextObjectPos = text.find_first_of("{[,");
    if (text[nextObjectPos] == ',')
    {
        buffer = text.substr(0, nextObjectPos);
        text.erase(0, nextObjectPos + 1);
        return readValue(buffer);
    }
    else if (nextObjectPos >= 0)
    {
        char otherChar;
        if (text.at(nextObjectPos) == '[')
            otherChar = ']';

        if (text.at(nextObjectPos) == '{')
            otherChar = '}';

        int endObjectPos = text.find(otherChar);
        buffer = text.substr(nextObjectPos, endObjectPos + 1);
        text.erase(nextObjectPos, endObjectPos + 1);
        if (text.front() == ',')
            text.erase(0, 1);
    }

    if (buffer[0] == '{' && buffer[buffer.length() - 1] == '}')
        return new Object(buffer);

    if (buffer[0] == '[' && buffer[buffer.length() - 1] == ']')
        return new Array(buffer);

    if (strtol(text.data(), nullptr, 10))
    {
        int number = strtol(text.data(), nullptr, 10);
        text.erase(0, digitCount(number));
        return new Integer(number);
    }

    buffer = text;
    text.erase(0, text.length());
    return new String(buffer);
}

std::vector<Value *> Object::search(std::string &sKey) const
{
    std::vector<Value *> values;
    for (size_t i = 0; i < jsonArray.size(); i++)
    {
        if (jsonArray[i].key == sKey)
            values.push_back(jsonArray[i].value);
        else if (jsonArray[i].value->getType() == JsonType::Array || jsonArray[i].value->getType() == JsonType::Object)
        {
            std::vector<Value *> toBeAdded = jsonArray[i].value->search(sKey);
            for (size_t j = 0; j < toBeAdded.size(); j++)
            {
                values.push_back(toBeAdded[j]);
            }
        }
    }
    return values;
}

void Object::set(std::string &path, std::string &value)
{
    std::string buffer;
    if (path.find("/") < path.npos)
        buffer = path.substr(path.find("/") + 1);

    for (size_t i = 0; i < jsonArray.size(); i++)
    {
        if (jsonArray[i].getKey() == path)
        {
            jsonArray[i].setValue(*readValue(value));
            return;
        }
    }

    path.erase(path.find("/"));

    for (size_t i = 0; i < jsonArray.size(); i++)
    {
        if (jsonArray[i].getKey() == path && (jsonArray[i].value->getType() == JsonType::Object || jsonArray[i].value->getType() == JsonType::Array))
            jsonArray[i].value->set(buffer, value);
    }
}

bool Object::contains(std::string &value) const
{
    bool contains = false;
    for (size_t i = 0; i < jsonArray.size(); i++)
    {
        if (jsonArray[i].value->contains(value))
            contains = true;
    }
    return contains;
}

Object::Object(std::string &text)
{
    // while (!text.empty())
    jsonArray.push_back(parse(text));
    setType(JsonType::Object);
}
