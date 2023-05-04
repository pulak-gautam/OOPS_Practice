#ifndef MOON_H
#define MOON_H

#include "planet.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class Moon : public Planet
{
public:
    std::map<std::string, double> Atmosphere;
    double waterInfo;

    // The atmospheric composition of the moon is about 33% neon, 33% helium and 33% hydrogen.
    // fixed default coordinates as well
    Moon(int x = 23, int y = 2, int z = 47, double Ne_content = 33, double He_content = 33, double H2_content = 33);
    void getAtmosphereInfo();
    void getWaterInfo();
};

#endif