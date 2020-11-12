/**
* @file logger.cpp
* @brief  Week 10, Google Earth Lab
*
* @author Rory Beebout
* @assignment Lab 10.2
* @date 11/12/2020
* @credits Prof Paden, for all except hostname and PID
* 
*/

#include "logger.h"
#include <unistd.h>

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
    std::string strTime;

    //get the time
    time_t logTime = time(0);
    strTime = ctime(&logTime);

    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize -1] = ' ';
        
    }

    pid_t pid = getpid();
    char hostName[_SC_HOST_NAME_MAX];
    gethostname(hostName, _SC_HOST_NAME_MAX);

    if (logFile)
    {

        logFile << strTime << hostName << " " << programName << "[" << pid << "]: " << msg << std::endl;
        return true;
    }
    else
    {
        return false;
    }
    
}