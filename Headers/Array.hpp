#include "Value.hpp"
#include "Object.hpp"
#include <vector>

#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array : public Value
{
private:
    std::vector<Object> objArray;

public:
    void print(std::ostream &output) const override;
    void saveprint(std::ostream &output) const override;
    bool contains(std::string &value) const override;
    std::vector<Value *> search(std::string &sKey) const override;
    void set(std::string &path, std::string &value) override;
    void create(std::string &path, std::string &value) override;
    void deleteJ(std::string &path) override;
    bool isEmpty() const override { return objArray.size(); }
    Value *getValue(std::string &path) override;
    void setValue(std::string &path, Value *ptr, std::string &key) override;
    Value *createCopy() override;

    Array(std::string &text);
    ~Array() = default;
};

#endif