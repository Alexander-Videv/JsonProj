#include <iostream>

class FileReader
{
private:
    std::istream *input;

public:
    FileReader(std::istream &input) { this->input = &input; };
    ~FileReader();
};
