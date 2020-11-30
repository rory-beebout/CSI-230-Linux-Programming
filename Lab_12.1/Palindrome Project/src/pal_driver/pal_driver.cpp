/**
* @file pal_driver.cpp
* @brief  Week 12, Palindrome Library Driver
*
* @author Rory Beebout
* @assignment Lab 12.1
* @date 11/30/2020
* @credits All credit to Faye Williams. Taken from https://www.fayewilliams.com/2015/07/07/creating-a-shared-library/
* 
*/
#include "pal.h"
#include <iostream>
 
using namespace std;
 
int main()
{
    while (1)
    {
        char buffer[64] = {0};
        cin >> buffer;
 
        if (isPalindrome(buffer))
        {
            cout << "Word is a palindrome" <<  endl;
        }
        else
        {
            cout <<  "Word is not a palindrome" <<  endl;
        }
    }
 
    return 0;
}