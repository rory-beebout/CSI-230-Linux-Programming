/**
* @file earthutils.h
* @brief  Week 10, Google Earth Lab
*
* @author Rory Beebout
* @assignment Lab 10.2
* @date 11/12/2020
* @credits Prof Paden
* 
*/
#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include <string>
#include <fstream>

//Constants
const std::string KMLHEADER = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n<Document>\n";;
const std::string KMLFOOTER = "</Document>\n</kml>\n";

/**
* @brief  process a country capital csv file
* @date 11/12/2020
* @author Devin Paden
* @return returns the number of records processed
* @param infile ifstream to an opened and validated csv file
* @param kmlFileName std::string containing the name of the kml file you wish to produce
* @param logFile ofstream reference, validation of this file is expected
*/
int processCSV(std::ifstream& inFile, std::string kmlFileName);

/**
* @brief  Writes a Placemark Record into an existing kmlFile
* @date 11/12/2020
* @author Devin Paden
* @param kmlfile ofstream reference to kmlfile to write in.
* @param name std::string representing concatenated Capital, Country
* @param latitude std::string representing latitude
* @param longitude std::string representing longitude
* @param elevation std::string representing elevation, defaults to 0
*/
void WritePlacemark(std::ofstream& kmlfile, std::string name, std::string latitude, std::string longitude, std::string elevation="0");
#endif