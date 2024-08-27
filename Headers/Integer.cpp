#include "Integer.hpp"

void Integer::print(std::ostream &output) const
{
    output << this->value;
}

bool Integer::contains(std::string &val) const
{
    int num = 0;
    num = strtol(val.data(), nullptr, 10);
    return value == num;
}

Value *Integer::createCopy() const
{
    return new Integer(*this);
}

Integer::Integer(int value)
{
    this->value = value;
    setType(JsonType::Integer);
}
