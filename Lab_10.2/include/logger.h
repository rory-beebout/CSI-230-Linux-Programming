/**
* @file logger.h
* @brief  Week 10, Google Earth Lab
*
* @author Rory Beebout
* @assignment Lab 10.2
* @date 11/12/2020
* @credits Prof Paden
* 
*/
#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>

/**
* @brief  creates a discrete syslog message
* @date 11/12/2020
* @author Devin Paden
* @return returns a boolean indicating the message was written ok
* @param msg std::string containing syslog message
* @param msg std::string containing the program name
* @param logFile ofstream reference, validation of this file is expected
*/
bool log(std::string msg, std::string programName, std::ofstream& logFile);
#endif