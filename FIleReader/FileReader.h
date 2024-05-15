#include <fstream>
#include <iostream>
#include "JsonHeaders\JsonObject.h"

#ifndef FILE_READER_H
#define FILE_READER_H

class FileReader
{
private:
    std::ifstream &input;

public:
    FileReader(std::ifstream &input);
    ~FileReader() = default;

    void write(std::ostream &os);
};

#endif