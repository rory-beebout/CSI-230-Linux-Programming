/**
* @file week10.cpp
* @brief  Week 10, C++ Review and Warmup from CSI140, util functions implementation file
*
* @author Rory Beebout
* @assignment Lab 10.1
* @date 10/26/2020
* @credits
* 
*/

#include "util.h"
#include <iostream>
#include <algorithm>

// template <typename T>
// T randomElement(std::vector<T> vec)
// {
    
//     int randomIndex = (rand() % vec.size());
//     return vec[randomIndex];
// }

double sum(std::vector<double> doublesVector)
{
    double sum = 0.0;
    for (auto itr : doublesVector)
    {
        sum += itr;
    }
    return sum;
}

double avg(std::vector<double> doublesVector)
{
    double vecSum = sum(doublesVector);
    double avg = vecSum/doublesVector.size();
    return avg;
}

double lowest(std::vector<double> doublesVector)
{
    double lowest = doublesVector.front();
    for (auto itr : doublesVector)
    {
        if (itr < lowest)
        {
            lowest = itr;
        }
    }
    return lowest;
}
void camelCase(std::string& string)
{
    string[0] = tolower(string[0]);
    char lastChar;
    for (char & c: string)
    {
        if (lastChar == ' ')
        {
            c = toupper(c);
        }
        lastChar = c;
    }
    string.erase(remove(string.begin(), string.end(), ' '), string.end());
}