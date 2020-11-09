/**
* @file week10.cpp
* @brief  Week 10, C++ Review and Warmup from CSI140
*
* @author Rory Beebout
* @assignment Lab 10.1
* @date 10/26/2020
* @credits
* 
*/
#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <stdlib.h>
#include <string>

/**
* @brief  returns ranom a element from a vector
* @date 10/26/2020
* @param vector<T> is the vector from which a random element will be returned.
* @return T will be a random element of the same type as is contained in the vector
*
* For the life of me, I could not define and implement randomElement() separately in
* .h and .cpp as specified, due to the way generic types are instantiated.
* so it is fully implemented here.
*/
template <typename T>
T randomElement(std::vector<T> vec)
{
    
    int randomIndex = (rand() % vec.size());
    return vec[randomIndex];
}

/**
* @brief  calculates, returns sum of all doubles in a vector
* @date 10/26/2020
* @param vector of doubles to be summed up
* @return double representing the sum total of all doubles in param vector
*/
double sum(std::vector<double>);

/**
* @brief  calculates, returns avg of all doubles in a vector
* @date 10/26/2020
* @param vector of doubles to take the average from
* @return double representing average of all doubles in param vector
*/
double avg(std::vector<double>);

/**
* @brief  returns the lowest double in a vector
* @date 10/26/2020
* @param vector of doubles to find the lowest value
* @return double equal to the lowest value double in param vector
*/
double lowest(std::vector<double>);

/**
* @brief  Converts a string to camelCase
* @date 10/26/2020
* @param string A string with spaces between words
* @return Void; Sets original string to camelCase version
*/
void camelCase(std::string&);
#endif