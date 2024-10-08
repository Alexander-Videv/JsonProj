#include "Array.hpp"

void Array::print(std::ostream &output) const
{
    output << "\n";
    for (size_t i = 0; i < objArray.size(); i++)
    {
        objArray[i]->print(output);
        output << "\n";
    }
}

void Array::saveprint(std::ostream &output) const
{
    output << "[\n";
    for (size_t i = 0; i < objArray.size(); i++)
    {
        objArray[i]->saveprint(output);
        if (i < objArray.size() - 1)
            output << ",\n";
    }
    output << "\n]";
}

bool Array::contains(std::string &value) const
{
    bool contains = false;
    for (size_t i = 0; i < objArray.size(); i++)
    {
        if (objArray[i]->contains(value))
            contains = true;
    }
    return contains;
}

std::vector<Value *> Array::search(std::string &sKey) const
{
    std::vector<Value *> values;
    for (size_t i = 0; i < objArray.size(); i++)
    {
        std::vector<Value *> toBeAdded = objArray[i]->search(sKey);
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
        objArray[i]->set(path, valueCopy);
    }
}

void Array::create(std::string &path, std::string &value)
{
    if (path.empty())
    {
        Object *obj = new Object(value);
        objArray.push_back(obj);
        return;
    }
    else
    {
        for (size_t i = 0; i < objArray.size(); i++)
        {
            if (objArray[i]->hasKey(path))
            {
                objArray[i]->create(path, value);
                return;
            }
        }
    }
    for (size_t i = 0; i < objArray.size(); i++)
    {
        try
        {
            objArray[i]->create(path, value);
            path.clear();
            return;
        }
        catch (const std::exception &e)
        {
            continue;
        }
    }
    Value::create(path, value);
}

void Array::deleteJ(std::string &path)
{
    if (path.empty())
        Value::deleteJ(path);

    std::string buffer = getSubpath(path);

    for (size_t i = 0; i < objArray.size(); i++)
    {
        if (objArray[i]->hasKey(buffer) && path.empty())
        {
            objArray[i]->deleteJ(buffer);
            objArray[i]->clearEmpty();
            if (objArray[i]->isEmpty())
                objArray.erase(objArray.begin() + i);

            return;
        }
        else if (objArray[i]->hasKey(buffer))
        {
            objArray[i]->deleteJ(path);
            objArray[i]->clearEmpty();
            if (objArray[i]->isEmpty())
                objArray.erase(objArray.begin() + i);

            return;
        }
    }
}

Value *Array::getValue(std::string &path)
{
    if (path.empty())
        return this;

    std::string buffer = getSubpath(path);

    for (size_t i = 0; i < objArray.size(); i++)
    {
        if (objArray[i]->hasKey(buffer) && path.empty())
        {
            return objArray[i]->getValue(buffer);
        }
        else if (objArray[i]->hasKey(buffer))
            return objArray[i]->getValue(path);
    }

    return nullptr;
}

void Array::setValue(std::string &path, Value *ptr, std::string &key)
{
    if (path.empty())
    {
        KeyValuePair pair(ptr, key);
        Object *obj = new Object();
        obj->push(&pair);
        objArray.push_back(obj);
        return;
    }

    std::string buffer = getSubpath(path);

    for (size_t i = 0; i < objArray.size(); i++)
    {
        if (objArray[i]->hasKey(buffer))
            objArray[i]->setValue(path, ptr, key);
    }
}

Value *Array::createCopy() const
{
    return new Array(*this);
}

std::string Array::getSubpath(std::string &path) const
{
    std::string buffer;
    if (path.find("/"))
    {
        buffer = path.substr(0, path.find("/"));
        path.erase(0, path.find("/") + 1);
    }
    else
    {
        buffer = path;
        path.clear();
    }

    return buffer;
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
        Object *obj = new Object(buffer);
        this->objArray.push_back(obj);
    }
    setType(JsonType::Array);
}