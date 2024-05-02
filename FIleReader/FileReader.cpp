#include "FileReader.h"
#include <string>

void FileReader::read(std::ostream &os)
{
    char output;
    std::string key, value;

    while (!input.eof())
    {
        input.ignore(100, '"');
        std::getline(input, key, '"');

        input.ignore(2);

        // std::getline(input, value, ',');

        JsonObject obj(key, value);
        obj.print(os);
        os << "  <- this is token" << "\n";
    }
}

FileReader::FileReader(std::ifstream &input) : input(input)
{
}