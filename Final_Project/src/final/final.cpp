/**
* @file final.cpp
* @brief  Week 14, Final Project Image Editing
*
* @author Rory Beebout
* @assignment Final Project Image Editing
* @date 12/14/2020
* 
*/
#include "final.h"
#include <string.h>

 
FIBITMAP* convertImageToGrey(FIBITMAP* image)
{
    image = FreeImage_ConvertToGreyscale(image);
    return image;
}
void inverseIntensify(FIBITMAP* image)
{
    FreeImage_AdjustContrast(image,100);
    FreeImage_Invert(image);
}
void flipImage(FIBITMAP* image)
{
    FreeImage_FlipHorizontal(image);
}