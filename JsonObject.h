#include <vector>
#include <string>

// this header file needs testing once i figure out a convenient way to separate information
// a key thing to debug and test is the key value pair as it will make or break this project
// finding the right way to setup the "key" pointer and the value is very important
// a good question to ask is how should i store duplicate keys as pointers
// a specific example might be looking at the json.json file we see a lot of "name" keys
// should the values point to '1' key or should i store separate keys to ease directory usage?

// Defing a family class for Json objects.
class JsonValue
{
protected:
    enum class TYPE
    {
        STRING,
        INTEGER,
        DATE,
        ARRAY,
        OBJECT
    };
    TYPE type;

    // private:
    JsonValue() = delete;
    JsonValue(TYPE type);
    ~JsonValue() = default;
};

// Defining a child class using the JsonValue class that will be storing a string
class JsonString : public JsonValue
{
private:
    std::string value;

public:
    JsonString();  // all of the constructors of these child classes should call the parametricized constructor
    ~JsonString(); // of the JsonValue class using the right type
};

// Defining a child class using the JsonValue class that will be storing an integer value
class JsonInteger : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    int value;

public:
    JsonInteger();
    ~JsonInteger();
};

// Defining a child class using the JsonValue class that will be storing a double value
// Problem with json files is they support unlimited digits after the floating point,
// for that reason i will be supporting up to 5 digits after the floating point
class JsonDouble : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    double value;

public:
    JsonDouble();
    ~JsonDouble();
};

// Defining a child class using the JsonValue class that will be storing a date
// for now i will be storing dates using simple strings, but that may be subject to change
class JsonDate : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    std::string value;

public:
    JsonDate();
    ~JsonDate();
};

// Defining a child class using the JsonValue class that will be storing an array of objects
// My first thought is storing the pointers to objects
class JsonArray : public JsonValue
{
private:
    JsonValue(TYPE::INTEGER);
    std::vector<JsonValue *> array;

public:
    JsonArray();
    ~JsonArray();
};

// Defining a child class using the JsonObject class that will be storing an object
// I will be storing 2 values in an object:
//  - a key that will be stored as a string
//  - and a pointer to the corresponding JsonValue
class JsonObject : public JsonValue
{
private:
    struct KeyValuePair
    {
    private:
        std::string key;
        JsonValue *value;
    };
    JsonValue(TYPE::OBJECT);
    std::vector<KeyValuePair> value;

public:
    JsonObject();
    ~JsonObject();
};

// Should ask if im storing keys as string and values as pointers or the other way around.
// Storing keys as a pointer to a string may be useful as i may have multiple values that point to that key
// on the other hand the move function might break this logic and i may need a copy/move operator and constructor
// need to test these out when i start writing functions