#include "FileReader.h"
#include <string>

void FileReader::print()
{
    char output;
    std::string token;

    while (!input.eof())
    {
        input.ignore(100, '"');
        std::getline(input, token, '{');

        JsonObject obj(token);
    }
}

FileReader::FileReader(std::ifstream &input) : input(input)
{
}