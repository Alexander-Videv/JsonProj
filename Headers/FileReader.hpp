#include <fstream>
#include <stdexcept>
#include "Object.hpp"

#ifndef FILE__READER__HPP
#define FILE__READER__HPP

class FileReader
{
public:
    void readCommand();

private:
    void parse();
    void validate();

    void askToSave();

    void open(std::string &filename);
    void exit();
    void print(std::ostream &output) const;

    // including path
    void save(std::string &path);
    void saveAs(std::string &path, std::string &filename) const;
    // path is empty
    void save()
    {
        std::string empty;
        save(empty);
    };
    void saveAs(std::string &filename) const
    {
        std::string empty;
        try
        {
            saveAs(empty, filename);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    };

    void search(std::string &sKey) const;
    bool contains(std::string &value) const;
    void set(std::string &path, std::string &value);
    void create(std::string &path, std::string &value);
    void pathDelete(std::string &path);
    void move(std::string &from, std::string &to);

    void removeNewLines(std::string &text) const;
    void removeQuotes(std::string &text) const;
    void removeSpaces(std::string &text) const;

    std::fstream file;
    Object Json;

    mutable bool saveFlag = true;
    bool validFlag = false;

public:
    FileReader() = default;
    ~FileReader();
};

#endif