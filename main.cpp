#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "functions.cpp"

// are there any other classes or structs i can build that can ease the whole proccess
// for instance is it good to add a file class that i build up on ifstream logic,
// can it help me to : / delete unnecesary symbols / split keys and values / also call the jsonObject header file
// so the logic can be split up between files and parsing, while working in tandem/

// need to clean up my includes

int main()
{
    // First thing to clear up is:
    // need to visualise my data set and to think of a good way to split it into usable strings / values
    // all of my logic will be built on the way i split up the file, so i need to make sure i find a good way

    // also need to clean up this whole comment

    // std::string input;
    // std::string readInput;
    //
    // std::ifstream inputFile;
    //
    // while (true)
    // {
    //     std::cin >> input;
    //     std::cin.ignore();
    //     // getline(input, readInput, ' ');
    //
    //     std::cout << input << '\n';
    //
    //     if (!input.compare("open"))
    //     {
    //         std::cout << "opening.";
    //         std::cin >> input;
    //         inputFile.open(input);
    //
    //         if (inputFile.is_open())
    //         {
    //             std::cout << "file " << input << " is opened\n";
    //         };
    //     }
    //     if (!readInput.compare("exit"))
    //     {
    //         std::cout << "Closing.";
    //
    //         break;
    //     }
    // }

    std::string input, output;

    std::getline(std::cin, input);

    std::ifstream ifs(input, std::ios::in);

    printJson(ifs);

    return 0;
}