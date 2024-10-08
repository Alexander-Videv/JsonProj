#include "Value.hpp"
#include <string>

#ifndef STRING_HPP
#define STRING_HPP

class String : public Value
{
private:
    std::string str;

public:
    void print(std::ostream &output) const override;
    void saveprint(std::ostream &output) const override { print(output); };

    bool contains(std::string &value) const override;
    Value *createCopy() const override;
    std::vector<Value *> search(std::string &sKey) const override
    {
        std::vector<Value *> null;
        return null;
    };

    String(std::string &string);
    ~String() = default;
};

#endif
