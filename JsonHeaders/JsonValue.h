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

public:
    JsonValue() = delete;
    JsonValue(TYPE type);
    virtual ~JsonValue() = default;
    // virtual void print() = 0;
};