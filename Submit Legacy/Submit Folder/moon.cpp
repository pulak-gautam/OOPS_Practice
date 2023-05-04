#include "moon.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

Moon::Moon(int x, int y, int z, double Ne_content, double He_content, double H2_content)
{
    this->positionX = x;
    this->positionY = y;
    this->positionZ = z;

    this->waterInfo = 0.5;

    Atmosphere["Ne"] = Ne_content;
    Atmosphere["He"] = He_content;
    Atmosphere["H2"] = H2_content;
}
void Moon::getAtmosphereInfo()
{
    std::cout << "\nPresent Atmosphere Composition on Moon is as follows:\n";
    for (auto i : Atmosphere)
    {
        std::cout << i.first << " --> " << i.second << "%" << std::endl;
    }
}
void Moon::getWaterInfo()
{
    std::cout << "\nPresent Water Availaibility on Moon is " << waterInfo << " million litres " << std::endl;
    std::cout << "We apologize for the inconvinence. We are constantly working towards bringing water scarcity on Moon to an end. Thank You" << std::endl;
}
