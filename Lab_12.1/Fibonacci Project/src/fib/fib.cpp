/**
* @file fib.h
* @brief  Week 12, Fibonacci Declarations
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

void PrintFibonacciSequence(int n)
{
    int t1 = 0, t2 = 1, nextTerm = 0;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i)
    {
        // Prints the first two terms.
        if(i == 1)
        {
            cout << t1 << " ";
            continue;
        }
        if(i == 2)
        {
            cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << " ";
    }
    cout << endl;
}