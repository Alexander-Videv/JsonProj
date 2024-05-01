#include <fstream>
#include <iostream>

class FileReader
{
private:
    std::ifstream &input;

public:
    FileReader(std::ifstream &input);
    ~FileReader() = default;

    void print();
};
