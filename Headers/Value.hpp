#include <iostream>
#include <vector>

#ifndef VALUE_HPP
#define VALUE_HPP

enum class JsonType
{
    String,
    Integer,
    Object,
    Array
};

class Value
{
private:
    JsonType myType;

public:
    void setType(JsonType type) { myType = type; };
    JsonType getType() { return myType; }
    virtual void print(std::ostream &output) const = 0;
    virtual void saveprint(std::ostream &output) const = 0;
    virtual bool contains(std::string &value) const = 0;
    virtual void create(std::string &path, std::string &value) { throw std::invalid_argument("Path or value cant be created!"); }
    virtual std::vector<Value *> search(std::string &sKey) const = 0;
    virtual void set(std::string &path, std::string &value) { throw std::invalid_argument("Path is invalid!"); };
    virtual void deleteJ(std::string &path) { throw std::logic_error("Path is invalid, object cant be deleted"); };
    virtual bool isEmpty() const { return false; }
    virtual Value *getValue(std::string &path)
    {
        if (path.empty())
            return this;
        throw std::logic_error("Path either doesent exist or is invalid.");
    }
    virtual void setValue(std::string &path, Value *ptr, std::string &key) { throw std::logic_error("Path wrong"); };

    virtual Value *createCopy() = 0;

    Value() = default;
    virtual ~Value() = default;
};

#endif