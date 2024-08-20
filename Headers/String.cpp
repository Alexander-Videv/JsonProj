#include "String.hpp"

String::String(std::string &string)
{
    str = string;
    setType(JsonType::String);
}

void String::print(std::ostream &output) const
{
    output << str;
}

bool String::contains(std::string &value) const
{
    return str.find(value) < str.npos;
}

Value *String::createCopy()
{
    // String str(*this);
    return new String(*this);
}
