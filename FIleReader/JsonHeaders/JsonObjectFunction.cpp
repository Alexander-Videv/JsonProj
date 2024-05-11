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

JsonValue *JsonObjectFactory(TYPE type)
{
    switch (type)
    {
    case TYPE::STRING:
        return new JsonString();
        break;
    case TYPE::INTEGER:
        return new JsonInteger();
        break;
    case TYPE::DATE:
        return new JsonDate();
        break;
    case TYPE::ARRAY:
        return new JsonArray();
        break;
    case TYPE::OBJECT:
        return new JsonObject();
        break;
    default:
        return nullptr;
        break;
    }
}