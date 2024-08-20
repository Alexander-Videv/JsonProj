#include "Value.hpp"
#include "Integer.hpp"
#include "KeyValuePair.hpp"
#include <vector>

#ifndef OBJECT_HPP
#define OBJECT_HPP

class Object : public Value
{

public:
    void print(std::ostream &output) const override;
    void saveprint(std::ostream &output) const override;
    void set(std::string &path, std::string &value) override;
    bool contains(std::string &value) const;
    std::vector<Value *> search(std::string &sKey) const override;
    void create(std::string &path, std::string &value) override;
    void deleteJ(std::string &path) override;

    Value *getValue(std::string &path) override;
    void setValue(std::string &path, Value *ptr, std::string &key) override;
    bool isEmpty() const override { return jsonArray.empty(); };
    void clearEmpty();

    Value *readValue(std::string &text);

    bool hasKey(std::string &key);
    void push(KeyValuePair *ptr) { this->jsonArray.push_back(*ptr); };
    Value *createCopy() override;

private:
    std::vector<KeyValuePair> jsonArray;

    KeyValuePair parse(std::string &text);

public:
    Object(std::string &text);
    Object() { setType(JsonType::Object); };
    ~Object() = default;
};

#endif