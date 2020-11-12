/**
* @file week10.cpp
* @brief  Week 10, Google Earth Lab
*
* @author Rory Beebout
* @assignment Lab 10.2
* @date 11/12/2020
* @credits Prof Paden, for writing most of this in Lab demo.
* 
*/

#include <iostream>
#include <unistd.h>
#include <libgen.h>
#include "logger.h"
#include "earth_utils.h"

using namespace std;

int main(int argc, char* argv[])
{
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    string kmlValue;
    string logValue;
    bool optErr = true;

    while ((opt = getopt(argc,argv, "k:l:"))!=EOF)
    {
        switch(opt)
        {
            case 'k':
            {
                kmlFlag = true;
                kmlValue = optarg;
                break;
            }
            case 'l':
            {
                logFlag = true;
                logValue = optarg;
                break;
            }
            default:
            {
                optErr = true;
                break;
            }
        }
    }
    cout << "flags - countFlag: " << kmlFlag << " logFlag: " << logFlag << endl;

    if (kmlFlag && logFlag)
    {
        cout << "flags set!" << endl;
        if (logValue.empty()|| kmlValue.empty())
        {
            optErr = true;
            cout << "option arguments are not set" << endl;
        }
        else 
        {
            ofstream flog;
            flog.open(logValue, ios_base::app);
            if(flog)
            {
                std::string programName = basename(argv[0]);
                std::string msg = "The kmlfile is:" + kmlValue + " and logfile is:" + logValue;
                log(msg, programName, flog);
                optErr = false;
                flog.close();

                ifstream inFile;
                inFile.open(kmlValue);
                if(inFile)
                {
                    int recordCount = processCSV(inFile, kmlValue + ".kml");
                    inFile.close();
                    if(recordCount)
                    {
                        cout << recordCount << " records processed" << endl;
                        optErr = false;
                    }
                    else
                    {
                        optErr = true;
                    }
                }
            }
        }
    }
    else
    {
        cout << "error - flags are not set!" << endl;
        optErr = true;
    }

    if (optErr)
    {
        return EXIT_FAILURE;
    }
    


    cout << "The count is: " << kmlValue << " and logfile is: " << logValue << endl;
    cout << "optErr: " << optErr << endl;

    return EXIT_SUCCESS;
}