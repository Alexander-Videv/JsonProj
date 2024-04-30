#include <fstream>
#include <iostream>
#include <string>

// i need to find a way to use getline as i need to derive keys and values not only symbols
// this file will be used to debug and prototype functions as it makes the workflow easier

void printJson(std::ifstream &jsonFile)
{
    // std::string line;
    char output;

    while (!jsonFile.eof())
    {
        // std::getline(jsonFile, line, '"');

        jsonFile.get(output);

        if (output == '{' || output == '}' || output == ']' || output == '"' || output == '\n' || output == ' ')
        {
            continue;
        }
        if (output == ',' || output == '[')
        {
            std::cout << '\n';
            continue;
        }

        std::cout << output;
    }
}