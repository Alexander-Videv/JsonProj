#include "JsonObject.h"

// whole cpp file need writing once i figure out some of the other logic of the header file
// which will come after i figure out the splitting of information
// this should be an easy file once i figure those things out

void JsonObject::print(std::ostream &os)
{

    this->value.print();
}

JsonValue::JsonValue(TYPE type)
{
    this->type = type;
}

JsonObject::JsonObject(std::string &str)
{
}