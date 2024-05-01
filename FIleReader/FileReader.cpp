#include "FileReader.h"

void FileReader::print()
{
    char output;
    std::cout << "im here";

    while (!input.eof())
    {

        input.get(output);

        if (output == '{' || output == '}' || output == ']' || output == '"' || output == '\n' || output == ' ')
        {
            continue;
        }
        if (output == ',' || output == '[')
        {
            std::cout << '\n';
            continue;
        }

        std::cout << output << ".";
    }
}

FileReader::FileReader(std::ifstream &input) : input(input)
{
}