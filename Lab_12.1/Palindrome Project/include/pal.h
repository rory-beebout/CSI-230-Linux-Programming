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
#ifndef PAL_H
#define PAL_H

/**
* @brief  creates a discrete syslog message
* @date 11/30/2020
* @author Faye Williams
* @return returns a boolean indicating the message was written ok
* @param word std::string containing syslog message
* @param logFile ofstream reference, validation of this file is expected
*/
bool isPalindrome(char* word);
#endif