/**
* @file logger.cpp
* @brief  Week 10, Google Earth Lab
* Implements google earth file handling utilities
* @author Rory Beebout
* @assignment Lab 10.2
* @date 11/12/2020
* @credits Prof Paden, for general format + most of the implementation
* 
*/

#include "earth_utils.h"
#include <sstream>
#include <iostream>

int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong;
    std::string strLine;
    int recordCount{};

    if (inFile)
    {
        std::ofstream kmlFile;
        kmlFile.open(kmlFileName);
        if(!kmlFile)
        {
            return recordCount;
        }
        kmlFile << KMLHEADER;

        getline(inFile, strLine);

        while(getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine);
            std::getline(s_stream, strCountry, ',');
            std::getline(s_stream, strCapital, ',');
            std::getline(s_stream, strLat, ',');
            std::getline(s_stream, strLong, ',');

            std::cout << strCountry + "~" + strCapital + "~" + strLat + "~" + strLong << std::endl;
            std::string placeName = strCountry + ", " + strCapital;
            WritePlacemark(kmlFile, placeName, strLat, strLong);
        }
        kmlFile << KMLFOOTER;
        kmlFile.close();
    }
}

void WritePlacemark(std::ofstream& kmlfile, std::string name, std::string latitude, std::string longitude, std::string elevation)
{
    if (kmlfile)
    {
        kmlfile << "<Placemark>\n";
        kmlfile << "<name>" << name << "</name>\n";
        kmlfile << "<Point>\n";
        kmlfile << "<coordinates>" << longitude << "," << latitude << "," << elevation << "</coordinates>\n";
        kmlfile << "</Point>\n";
        kmlfile  << "</Placemark>\n";
    }
}