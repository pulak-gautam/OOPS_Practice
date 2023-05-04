#ifndef COMMANDER_H
#define COMMANDER_H

#include "traveller.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class Commander : public Traveller
{
private:
    int experience;
    int licenseId;
    int authority;

public:
    std::set<int> allottedTravels;
    static std::vector<Commander *> listCommanders;

    Commander(std::string name = "", int id = 0, int authority = 0, int experience = 0, int licenseId = 0);

    int getLicenseId();
    void setlicenseId(int licenseId);

    int getExperience();
    void setExperience(int experience);

    void setAuthority(int authority);

    static Commander *assignCommander(int travelId);
};

#endif