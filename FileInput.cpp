#include "FileInput.h"
#include <iostream>

bool FileInput::handlerInputFile(const std::string &filename, std::ifstream &ifs)
{
    if(filename.empty())
    {
        return false;
    }
    try
    {
        ifs.open(filename);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;    
}
