#include "Compress.h"
#include <cctype>

const std::string Compress::rle(const std::string &str)
{
    int strSize = str.size();
    std::string result;
    int count = 1;
    char prev = str[0];


    for(int i = 1; i < strSize; ++i)
    {
        if(prev == str[i])
        {
            ++count;
        }
        else
        {
            result += std::to_string(count) + prev;
            count = 1;
            prev = str[i];
        }
    }
    result += std::to_string(count) + prev;
    return result;
}

const std::string Compress::drle(const std::string &str)
{
    std::string result;
    std::string num;
    int strSize = str.size();

    for(int i = 0; i < strSize; ++i)
    {
        if(isdigit(str[i]))
        {
            num += str[i];
        }
        else
        {
            int number = stoi(num);
            while(number --> 0)
            {
                result += str[i];
            }
            num = "";
        }
    }
    return result;
}
