#ifndef MARS_H
#define MARS_H

#include "planet.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class Mars : public Planet
{
public:
    std::map<std::string, double> Atmosphere;
    double waterInfo;
    double inhabitants;

    // Mars' atmosphere is composed of 95.32% carbon dioxide, 2.7% nitrogen, 1.6% argon and 0.13% oxygen
    // fixed default coordinates as well
    Mars(int x = 49, int y = 52, int z = 64, double CO2_content = 95.32, double N2_content = 2.7, double Ar_content = 1.6, double O2_content = 0.13);
    void getAtmosphereInfo();
    void getInhabitantsInfo();
    void getWaterInfo();
};

#endif