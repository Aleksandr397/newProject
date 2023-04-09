#include "Compress.h"

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
    return result;
}
