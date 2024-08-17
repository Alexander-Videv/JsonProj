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

    Array(std::string &text);
    ~Array() = default;
};

#endif