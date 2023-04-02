#pragma once
#include <string>
#include <fstream>

class FileInput
{
public:
   static bool handlerInputFile(const std::string& filename, std::ifstream &ifs);
private:

};