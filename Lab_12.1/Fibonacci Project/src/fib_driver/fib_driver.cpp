/**
* @file fib.h
* @brief  Week 12, Fibonacci Driver
*
* @author Rory Beebout
* @assignment Lab 12.1
* @date 11/30/2020
* @credits Taken from https://www.programiz.com/cpp-programming/examples/fibonacci-series
* 
*/
#include "fib.h"
#include <iostream>
 
using namespace std;
 
int main()
{
    while (1)
    {
        int buffer = 0;
        cin >> buffer;
 
        PrintFibonacciSequence(buffer);
    }
 
    return 0;
}