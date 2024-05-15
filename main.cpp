#include <fstream>
#include <string>
#include "FIleReader/FileReader.h"
#include "FIleReader/JsonHeaders/JsonObject.h"
#include "FileReader/FileReader.cpp"
// #include "FileReader/JsonHeaders/JsonObject.cpp"
#include "FIleReader/JsonHeaders/JsonObjectFunction.cpp"

int main()
{

    std::string input, output;
    // std::getline(std::cin, input);

    input = "test.json";

    std::ifstream file(input);

    FileReader read(file);

    read.write(std::cout);

    return 0;
}