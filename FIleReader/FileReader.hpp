#include <fstream>
#include <iostream>
#include "JsonHeaders\JsonObject.h"

#ifndef FILE_READER_H
#define FILE_READER_H

class FileReader
{
private:
    std::string fileName;
    std::string json;

    std::string removeNewLines(std::ifstream &input);
    std::string ignoreSpaces(std::string &other);

    void open(std::istream &filename);
    void save();
    void saveAs(std::istream &filename);
    void exit();
    void parse();

public:
    FileReader() = default;
    ~FileReader() = default;

    void getCommand(std::istream &is);
    void write(std::ostream &output);
};

#endif