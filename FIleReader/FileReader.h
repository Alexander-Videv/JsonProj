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
};
