#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include "traveller.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class Astronaut : public Traveller
{
private:
    int licenseId;
    int experience;

public:
    std::set<int> allottedTravels;
    static std::vector<Astronaut *> listAstronauts;

    Astronaut(std::string name = "", int travellerId = 0, int experience = 0, int licenseId = 0);

    int getExperience();
    void setExperience(int experience);

    int getLicenseId();
    void setLicenseId(int licenseId);

    static Astronaut *assignAstronaut(int travelId);
};

#endif