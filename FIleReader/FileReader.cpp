#include "FileReader.hpp"
#include <string>
#include <cstring>

std::string FileReader::removeNewLines(std::ifstream &input)
{
    std::string line;
    std::string output = "";
    while (!input.eof())
    {
        std::getline(input, line);
        output += ignoreSpaces(line);
    }

    return output;
}

std::string FileReader::ignoreSpaces(std::string &other)
{
    char p;
    std::string newString = "";
    for (size_t i = 0; i < other.length(); i++)
    {
        if (other[i] == ' ')
            continue;
        else
            p = other[i];

        newString += p;
    }

    return newString;
}

void FileReader::open(std::istream &filename)
{
    std::getline(filename, this->fileName);

    std::ifstream file(this->fileName);

    if (!file.is_open())
        throw std::invalid_argument("File can't be opened");

    std::cout << "Successfully opened " << this->fileName << "\n";
    this->json = removeNewLines(file);
    file.close();

    parse();
}

void FileReader::save()
{
    std::ofstream file(fileName);
    file << this->json;
}

void FileReader::saveAs(std::istream &filename)
{
    std::string fileString;
    std::getline(filename, fileString);

    std::ofstream file(fileString);

    if (!file.is_open())
        throw std::invalid_argument("File can't be opened");

    file << this->json;
    file.close();
}

void FileReader::exit()
{
    std::cout << "Exiting";
}

void FileReader::getCommand(std::istream &is)
{
    std::string input;
    std::string command;

    while (true)
    {
        std::getline(is, command, ' ');
        std::cout << command;

        if (command == "open")
        {
            try
            {
                open(is);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (command == "save")
            save();

        if (command == "saveas")
            saveAs(is);

        if (command == "write")
            write(std::cout);

        if (command == "exit")
        {
            exit();
            break;
        }

        is.clear();
    }
}

void FileReader::write(std::ostream &output)
{
    std::cout << fileName << " : " << json << "\n";
}
