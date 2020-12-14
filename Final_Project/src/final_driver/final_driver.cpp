/**
* @file final_driver.cpp
* @brief  Week 14, Final Project Image Editing
*
* @author Rory Beebout
* @assignment Final Project Image Editing
* @date 12/14/2020
* 
*/
#include "final.h"
#include <fstream>
#include <iostream>
#include <string>
#include "FreeImagePlus.h"
 
using namespace std;
 
int main(int argc, char** argv)
{
    FreeImage_Initialise();
    for (int i = 1; i < argc; i++)
    {
        int arg = 1;
        FIBITMAP* baseImage = FreeImage_Load(FIF_PNG, argv[i],0);
        int size = FreeImage_GetMemorySize(baseImage);
        if (size < 5)
        {
            cout << "\n File " << i << " of " << argc -1;
            cout << "\n"<< argv[i]<<" - File not found. Continuing to next.";
            continue;
        }
        FIBITMAP* newImage = FreeImage_Clone(baseImage);

        
        while (arg != 0)
        {
            cout << "\n File " << i << " of " << argc -1;
            cout << "\nCurrent File: " << argv[i] << "\n";
            cout << "Enter number corresponding to desired action\n"
                << "1. Invert and Intensify\n"
                << "2. Convert to Greyscale\n"
                << "3. Horizontal Flip\n";
            cin >> arg;
            switch(arg)
            {
                case 1:
                {
                    inverseIntensify(newImage);
                    break;
                }
                case 2:
                {
                    newImage = convertImageToGrey(newImage);
                    break;
                }
                case 3:
                {
                    flipImage(newImage);
                    break;
                }
            }
        }
        cout << "Save file as: \n";
        string filename;
        cin >> filename;
        filename.append(".png");
        FreeImage_Save(FIF_PNG,newImage,filename.c_str());
    }
    cout << "\n Done \n";
    FreeImage_DeInitialise();
    
    return 0;
}