#include <fstream>
#include <string>
#include <sstream>
#include "FIleReader/FileReader.hpp"

int main()
{

    FileReader console;

    std::istringstream input("open test.json\nwrite exit ");

    console.getCommand(input);
    // console.write(std::cout);

    return 0;
}