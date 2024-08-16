#include "Headers/FileReader.hpp"
#include "Headers/FileReader.cpp"
#include "Headers/Integer.hpp"
#include "Headers/Integer.cpp"
#include "Headers/KeyValuePair.hpp"
#include "Headers/KeyValuePair.cpp"
#include "Headers/Object.hpp"
#include "Headers/Object.cpp"
#include "Headers/String.hpp"
#include "Headers/String.cpp"
#include "Headers/Array.hpp"
#include "Headers/Array.cpp"
#include "Headers/Value.hpp"

int main()
{
    FileReader jsonFile;

    try
    {
        jsonFile.readCommand();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}