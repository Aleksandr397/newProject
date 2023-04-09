#pragma once
#include <string>
#include <fstream>
#include <functional>
#include "Compress.h"


class Programm
{
public:
    void run(int argc, char** argv);

private:
    void handleInputArgs(int argc, char **argv);
    void handleAlgExecution();
    std::string executeAlg(std::function<const std::string(const std::string &)> func, const std::string &str);

private:
    std::string m_inputFile;
    std::string m_outputFile;
    std::string m_algorithm; 
    std::ifstream m_ifs;
    std::ofstream m_ofs;

};
