/**
* @file week10.cpp
* @brief  Week 10, C++ Review and Warmup from CSI140
*
* @author Rory Beebout
* @assignment Lab 10.1
* @date 10/26/2020
* @credits
* 
*/

#include <iostream>
#include <time.h>
#include "util.h"

using namespace std;

int main()
{
    //seed rng
    srand(time(0));

    //In main(), create a vector of strings with at least 5 string objects
    vector<string> stringsVector;
    stringsVector.push_back("Yuna");
    stringsVector.push_back("Raava");
    stringsVector.push_back("Setsuna");
    stringsVector.push_back("Puck");
    stringsVector.push_back("The Morrigan");

    //Call a function called randomElement
    string randomElementChosen = randomElement(stringsVector);

    //In main, create a vector of doubles with at least 5 different values.
    vector<double> doublesVector;
    doublesVector.push_back(1.2);
    doublesVector.push_back(2.2);
    doublesVector.push_back(3.2);
    doublesVector.push_back(4.2);
    doublesVector.push_back(5.2);

    //In main, create a multi word string like "A little bird with a yellow bill"
    string multiWord = "The past marches with me. A legion of one!";

    //For Screenshot
    cout << "Dumping the Vector of 5 Elements: "<< "\n";
    for (auto it: stringsVector)
    {
        cout << it << " ";
    }
    cout << "\n";
    cout << "Srand set" << "\n";
    cout << "calling randomElement" << "\n";
    cout << randomElement(stringsVector) << "\n";
    cout << "Dumping the vector of doubles" << "\n";
    for (auto it: doublesVector)
    {
        cout << it << " ";
    }
    cout << "\n";
    cout << "sum: " << sum(doublesVector) << "\n";
    cout << "avg:" << avg(doublesVector) << "\n";
    cout << "lowest:" << lowest(doublesVector) << "\n";
    cout << "Calling camelCase with: " << multiWord << "\n";
    camelCase(multiWord);
    cout << "strMessage after camelCase: " << multiWord << "\n";
    cout << "\n";

    return EXIT_SUCCESS;
}