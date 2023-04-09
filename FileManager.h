#pragma once
#include <string>
#include <fstream>
#include <iostream>

template <typename T>
class FileManager
{
public:
   static bool handleFileOpen(const std::string& filename, T &fs)
   {
   if(filename.empty())
   {
      return false;
   }

   if(fs.is_open())
   {
      fs.close();
   }

   try
   {
      fs.open(filename);
   }
   catch(const std::exception &e)
   {
      std::cerr << e.what() << std::endl;
      return false;
   }
   return true;
   }
};
