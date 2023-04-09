#include "Programm.h"
#include "FileManager.h"
#include <iostream>
#include <string>
#include <fstream>

void Programm::run(int argc, char **argv)
{
    handleInputArgs(argc, argv);
    FileManager<std::ifstream>::handleFileOpen(m_inputFile, m_ifs);
    FileManager<std::ofstream>::handleFileOpen(m_outputFile, m_ofs);
    handleAlgExecution();
}

Programm::Programm()
{
    m_algMap.insert(std::make_pair("-rle", &Compress::rle));
    m_algMap.insert(std::make_pair("-RLE", &Compress::rle));
    m_algMap.insert(std::make_pair("-drle", &Compress::rle));
    m_algMap.insert(std::make_pair("-dRLE", &Compress::rle));

}

Programm::~Programm()
{
    if(m_ifs.is_open())
    {
        m_ifs.close();
    }
    if(m_ofs.is_open())
    {
        m_ofs.close();
    }
}

void Programm::handleInputArgs(int argc, char **argv)
{
    if(argc == 2)
    {
        if(std::string(argv[1]) == "-help")
        {
            std::cout << "Use this argument format: " << std::endl;
            std::cout << "[input_file_name] [output_file_name] [algorithm] " << std::endl;
            std::cout << "\t--------------------\t" << std::endl;
            std::cout << "Available algorithm list:" << std::endl;
            std::cout << "-rle or -RLE: run-length encoding" << std::endl;
            std::cout << "-drle or -dRLE: run-length encoding (decompression)" << std::endl;

        }
        else
        {
            std::cout << "Plese use -help for info" << std::endl;
        }
        return;

        if(argc == 3)
        {
            m_inputFile = argv[1];
            m_outputFile = argv[2];
            m_algorithm = "-rle";
            return;
        }

        if(argc == 4)
        {
            m_inputFile = argv[1];
            m_outputFile = argv[2];
            m_algorithm = argv[4];
            return;
        }
    }

  /*  for(int i = 1; i < argc; ++i)
    {
        if(i == 1 && std::to_string(argv[i][0]) != std::to_string('-'))
        {
            m_inputFile = std::string(argv[i]);
            continue;
        }
        if(i == 2 && std::to_string(argv[i][0]) != std::to_string('-'))
        {
            m_outputFile = std::string(argv[i]);
            continue;
        }
        if(std::to_string(argv[i][0]) == std::to_string('-'))
        {
            m_algorithm = std::string(argv[i]);
        }
    }
    */
}

void Programm::handleAlgExecution()
{
    executeAlg(m_algMap[m_algorithm], m_ifs, m_ofs);

}

void Programm::executeAlg(std::function<const std::string(const std::string &)> func, 
                                                                            std::ifstream &ifs,
                                                                            std::ofstream &ofs)
{
        for(std::string inputLine; std::getline(m_ifs, inputLine);)
        {
            std::string outputLine = func(inputLine);
            ofs << outputLine << std::endl;
        }   
}
