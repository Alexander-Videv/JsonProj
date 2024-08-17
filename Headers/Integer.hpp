#include "Value.hpp"

#ifndef INTEGER__HPP
#define INTEGER__HPP

class Integer : public Value
{
private:
    int value;

public:
    void print(std::ostream &output) const override;
    void saveprint(std::ostream &output) const override { print(output); };

    std::vector<Value *> search(std::string &sKey) const override
    {
        std::vector<Value *> null;
        return null;
    };
    bool contains(std::string &val) const override;

    Integer(int value);
    ~Integer() = default;
};

#endif