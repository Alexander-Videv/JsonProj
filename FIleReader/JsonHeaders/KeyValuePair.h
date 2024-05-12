struct KeyValuePair
{
public:
    std::string key;
    JsonValue *value;

public:
    void print(std::ostream &os) const;
};