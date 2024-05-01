#include <fstream>
#include <string>
#include "FileReader/FileReader.cpp"

int main()
{

    std::string input, output;
    // std::getline(std::cin, input);

    input = "test.json";

    std::ifstream file(input);

    FileReader read(file);

    read.print();

    return 0;
}