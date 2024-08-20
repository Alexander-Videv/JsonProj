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

void Object::saveprint(std::ostream &output) const
{
    output << "{\n";
    for (int i = jsonArray.size() - 1; i >= 0; i--)
    {
        jsonArray[i].saveprint(output);
        if (i != 0)
            output << ",\n";
    }
    output << "\n}";
}
void Object::print(std::ostream &output) const
{
    for (int i = jsonArray.size() - 1; i >= 0; i--)
    {
        jsonArray[i].print(output);
        if (i != 0)
            output << " ";
    }
}

void Object::clearEmpty()
{
    for (size_t i = 0; i < jsonArray.size(); i++)
    {
        if (jsonArray[i].isEmpty())
        {
            jsonArray.erase(jsonArray.begin() + i);
        }
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
    text.clear();
    return new String(buffer);
}

bool Object::hasKey(std::string &key)
{
    for (size_t i = 0; i < jsonArray.size(); i++)
    {
        if (key == jsonArray[i].getKey())
            return true;
    }

    return false;
}

Value *Object::createCopy()
{
    // Object obj(*this);
    return new Object(*this);
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

void Object::create(std::string &path, std::string &value)
{
    std::string buffer;
    if (path.find("/") < path.npos)
        buffer = path.substr(0, path.find("/"));

    for (size_t i = 0; i < jsonArray.size(); i++)
    {
        if (path.empty())
            break;
        if (jsonArray[i].getKey() == buffer || jsonArray[i].getKey() == path)
        {
            if (!buffer.empty())
            {
                path.erase(0, buffer.size() + 1);
                buffer.clear();
                jsonArray[i].value->create(path, value);
                return;
            }
            else
            {
                path.clear();
                jsonArray[i].value->create(path, value);
                return;
            }
        }
    }
    std::string key;
    if (value.find(":") < value.npos)
    {
        key = value.substr(0, value.find(":"));
        value.erase(0, value.find(":") + 1);
    }

    KeyValuePair pair;
    if (key.empty())
    {
        pair.setKey(path);
    }
    else
    {
        pair.setKey(key);
    }
    pair.setValue(*readValue(value));
    jsonArray.push_back(pair);
}

void Object::deleteJ(std::string &path)
{
    std::string buffer;
    if (path.find("/") < path.npos)
        buffer = path.substr(0, path.find("/"));

    for (size_t i = 0; i < jsonArray.size(); i++)
    {
        if (jsonArray[i].getKey() == path)
        {
            jsonArray.erase(jsonArray.begin() + i);
            path.clear();

            break;
        }

        if (jsonArray[i].getKey() == buffer)
        {
            path.erase(0, buffer.size() + 1);
            buffer.clear();
            jsonArray[i].value->deleteJ(path);
            break;
        }
    }
}

Value *Object::getValue(std::string &path)
{
    if (path.empty())
        return this;

    std::string buffer;
    if (path.find("/") < path.npos)
    {
        buffer = path.substr(0, path.find("/"));
        path.erase(0, path.find("/") + 1);
    }
    else
    {
        buffer = path;
        path.clear();
    }

    for (size_t i = 0; i < jsonArray.size(); i++)
    {
        if (jsonArray[i].getKey() == buffer)
            return jsonArray[i].value->getValue(path);
    }

    return nullptr;
}

void Object::setValue(std::string &path, Value *ptr, std::string &key)
{
    if (path.empty() || path == " ")
    {
        KeyValuePair pair(ptr, key);
        jsonArray.push_back(pair);
        return;
    }

    std::string buffer;
    if (path.find("/") < path.npos)
    {
        buffer = path.substr(0, path.find("/"));
        path.erase(0, path.find("/") + 1);
    }
    else
    {
        buffer = path;
        path.clear();
    }

    for (size_t i = 0; i < jsonArray.size(); i++)
    {
        if (jsonArray[i].getKey() == buffer)
            jsonArray[i].value->setValue(path, ptr, key);
    }
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
    jsonArray.push_back(parse(text));
    setType(JsonType::Object);
}
