#include "JsonValue.h"
#include "JsonObject.h"
#include "JsonString.h"
#include "JsonInteger.h"
#include "JsonDouble.h"
#include "JsonDate.h"
#include "JsonArray.h"

enum class TYPE
{
    STRING,
    INTEGER,
    DATE,
    ARRAY,
    OBJECT
};

JsonValue *JsonObjectFactory(TYPE type, std::string &key, std::string &value)
{
    switch (type)
    {
    case TYPE::STRING:
        return new JsonString(key, value);
        break;
    case TYPE::INTEGER:
        return new JsonInteger(key, value);
        break;
    case TYPE::DATE:
        return new JsonDate(key, value);
        break;
    case TYPE::ARRAY:
        return new JsonArray(key, value);
        break;
    case TYPE::OBJECT:
        return new JsonObject(key, value);
        break;
    default:
        return nullptr;
        break;
    }
}

TYPE parse(std::string &value)
{
    return TYPE::STRING;
}
