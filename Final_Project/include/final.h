/**
* @file final.h
* @brief  Week 14, Final Project Image Editing
*
* @author Rory Beebout
* @assignment Final Project Image Editing
* @date 12/14/2020
* 
*/
#ifndef FINAL_H
#define FINAL_H

#include <string>
#include "FreeImagePlus.h"

//## Constants ##
std::string filepath = "/home/rorybeebout/Pictures/";

/**
* @brief  converts the given bitmap to greyscale
* @date 12/14/2020
* @return returns a boolean indicating the message was written ok
* @param FIBITMAP* takes in a FIBITMAP from FreeImage library to modify.
*/
FIBITMAP* convertImageToGrey(FIBITMAP* image);

/**
* @brief  inverts the colors on a given bitmap, and doubles "contrast"
* @date 12/14/2020
* @return returns a boolean indicating the message was written ok
* @param FIBITMAP* takes in a FIBITMAP from FreeImage library to modify.
*/
void inverseIntensify(FIBITMAP* image);

/**
* @brief  horizontally flips a given bitmap
* @date 12/14/2020
* @return returns a boolean indicating the message was written ok
* @param FIBITMAP* takes in a FIBITMAP from FreeImage library to modify.
*/
void flipImage(FIBITMAP* image);

#endif