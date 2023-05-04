#include "mars.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

Mars::Mars(int x, int y, int z, double CO2_content, double N2_content, double Ar_content, double O2_content)
{
    this->positionX = x;
    this->positionY = y;
    this->positionZ = z;

    this->waterInfo = 40;
    this->inhabitants = 14;

    Atmosphere["CO2"] = CO2_content;
    Atmosphere["N2"] = N2_content;
    Atmosphere["Ar"] = Ar_content;
    Atmosphere["O2"] = O2_content;
}

void Mars::getAtmosphereInfo()
{
    std::cout << "Present Atmosphere Composition on Mars is as follows:\n";
    for (auto i : Atmosphere)
    {
        std::cout << i.first << " --> " << i.second << "%" << std::endl;
    }

    std::cout << "Please carry MARS (Mars' Atmosphere Respiratory Set) if you plan to visit Mars. Thank You!\n";
}

void Mars::getInhabitantsInfo()
{
    std::cout << "\nPresent Inhabitant Population on Mars is " << inhabitants << " million" << std::endl;
}

void Mars::getWaterInfo()
{
    std::cout << "\nPresent Water Availaibility on Mars is" << waterInfo << " per capita " << std::endl;
}