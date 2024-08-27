#include "Value.hpp"
#include "Object.hpp"
#include <vector>

#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array : public Value
{
public:
    void print(std::ostream &output) const override;
    std::vector<Value *> search(std::string &sKey) const override;
    bool contains(std::string &value) const override;
    void set(std::string &path, std::string &value) override;
    void create(std::string &path, std::string &value) override;
    void deleteJ(std::string &path) override;

    void setValue(std::string &path, Value *ptr, std::string &key) override;
    Value *getValue(std::string &path) override;
    Value *createCopy() const override;

    void saveprint(std::ostream &output) const override;

    bool isEmpty() const override { return objArray.size(); }

private:
    std::string getSubpath(std::string &path) const;

public:
    Array(std::string &text);
    ~Array() = default;

private:
    std::vector<Object *> objArray;
};

#endif