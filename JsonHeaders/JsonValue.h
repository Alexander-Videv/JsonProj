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