#include "FileReader.hpp"
#include <sstream>

void FileReader::validate()
{
    if (!file.is_open())
        throw std::invalid_argument("No file is opened!");
    try
    {
        parse();
        validFlag = true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return;
}

void FileReader::askToSave()
{
    if (!validFlag)
        throw std::invalid_argument("Invalid object cant be saved");
    std::cout
        << "Do you want to save changes?" << '\n'
        << "Y/N" << '\n';
    char input;
    std::cin >> input;
    while (input != 'Y' || input != 'N' || input != 'y' || input != 'n')
    {
        std::cout << "Invalid character." << '\n';
        std::cin >> input;
    }
    if (input == 'Y' || input == 'y')
        save();
    else
        saveFlag = true;
    exit();
}

void FileReader::search(std::string &sKey) const
{
    std::vector<Value *> values;
    if (validFlag)
        values = Json.search(sKey);

    if (!values.empty())
        for (int i = values.size() - 1; i >= 0; i--)
        {
            std::cout << "\"";
            values[i]->print(std::cout);
            std::cout << "\"";
            std::cout << "\n";
        }
    else
        std::cout << "No objects match given key!" << '\n';
}

bool FileReader::contains(std::string &value) const
{
    return Json.contains(value);
}

void FileReader::set(std::string &path, std::string &value)
{
    try
    {
        Json.set(path, value);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void FileReader::parse()
{
    if (!file.is_open())
        throw std::invalid_argument("File is not open");

    std::string text = "";
    std::string buffer;
    while (file.good())
    {
        std::getline(file, buffer);
        text += buffer;
    }

    removeQuotes(text);
    removeNewLines(text);
    removeSpaces(text);

    Json = Object(text);
}

void FileReader::removeNewLines(std::string &text) const
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '\n')
        {
            text[i] = ' ';
        }
    }
}

void FileReader::removeQuotes(std::string &text) const
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '"')
        {
            text[i] = ' ';
        }
    }
}

void FileReader::removeSpaces(std::string &text) const
{
    for (size_t i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            text.erase(i, 1);
            i--;
        }
    }
}

void FileReader::readCommand()
{
    while (true)
    {
        std::string input;

        std::getline(std::cin, input);

        int pos = 0;
        pos = input.find(" ");

        std::string buffer;
        if (pos > 0)
        {
            buffer = input.substr(0, pos);

            input.erase(0, pos + 1);
            input.shrink_to_fit();
        }
        // add commands here
        if (buffer == "open")
        {
            try
            {
                open(input);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (buffer == "save")
            save(input);
        if (buffer == "set")
        {
            std::string path = input.substr(0, input.find(' '));
            input.erase(0, input.find(' ') + 1);
            removeQuotes(path);
            removeQuotes(input);
            removeSpaces(path);
            removeSpaces(input);
            set(path, input);
        }
        if (buffer == "search")
        {
            if (input[0] == '\"' && input[input.length() - 1] == '\"')
            {
                input.erase(0, 1);
                input.erase(input.rfind('\"'), 2);
            }
            removeQuotes(input);
            search(input);
        }
        if (buffer == "saveas")
            saveAs(input);
        if (input == "save")
            save();
        if (input == "print")
            print(std::cout);
        if (input == "exit")
            break;
    }
}

void FileReader::open(std::string &filename)
{
    this->file.open(filename);

    if (!file.good())
        throw std::invalid_argument("Json file can't be opened");

    validFlag = true;

    parse();
}

void FileReader::save(std::string &path)
{
    if (path.empty())
    {
        try
        {
            Json.print(file);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    saveFlag = true;
}

void FileReader::saveAs(std::string &path, std::string &filename) const
{
    std::fstream newFile("jsonTest.txt");
    if (!newFile.good())
        throw std::logic_error("The file you want to save in can't be opened");
    if (path.empty())
    {
        try
        {
            Json.print(newFile);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    newFile.close();

    saveFlag = true;
}

void FileReader::print(std::ostream &output) const
{
    if (!validFlag)
        throw std::logic_error("Cant print invalid file");
    Json.print(output);
    output << "\n";
}

void FileReader::exit()
{
    if (!saveFlag)
        askToSave();

    file.close();
}

FileReader::~FileReader()
{
    exit();
}
