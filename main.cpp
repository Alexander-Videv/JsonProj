#include <fstream>
#include <string>
#include "FileReader/FileReader.cpp"
#include "FileReader/JsonHeaders/JsonObject.cpp"

int main()
{

    std::string input, output;
    // std::getline(std::cin, input);

    input = "test.json";

    std::ifstream file(input);

    FileReader read(file);

    read.read(std::cout);

    return 0;
}