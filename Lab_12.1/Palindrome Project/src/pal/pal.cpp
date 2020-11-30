/**
* @file pal.h
* @brief  Week 12, Palindrome Declarations
*
* @author Rory Beebout
* @assignment Lab 12.1
* @date 11/30/2020
* @credits Faye Williams. Taken from https://www.fayewilliams.com/2015/07/07/creating-a-shared-library/
* 
*/
#include "pal.h"
#include <string.h>
 

bool isPalindrome(char* word)
{
    bool ret = true;
 
    char *p = word;
    int len = strlen(word);
    char *q = &word[len-1];
 
    for (int i = 0 ; i < len ; ++i, ++p, --q)
    {
        if (*p != *q)
        {
            ret = false;
        }
    }
 
    return ret;
}