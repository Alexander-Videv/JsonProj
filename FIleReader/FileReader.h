#include <fstream>
#include <iostream>
#include "JsonHeaders\JsonObject.h"

class FileReader
{
private:
    std::ifstream &input;

public:
    FileReader(std::ifstream &input);
    ~FileReader() = default;

    void read(std::ostream &os);

public:
    void toOBject(std::istream &is);
    void toArray(std::istream &is);
    void toString(std::istream &is);
    void toInteger(std::istream &is);
    void toDouble(std::istream &is);
    void toDate(std::istream &is);
};
