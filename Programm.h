#pragma once
#include <string>

class Programm
{
public:
    void run(int argc, char** argv);

private:
    void handleInputArgs(int argc, char **argv);
private:
    std::string m_inputFile;
    std::string m_outputFile;
    std::string m_algorithm; 

};
