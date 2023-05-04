#include "commander.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

Commander::Commander(std::string name, int id, int authority, int experience, int licenseId)
{
    this->updateName(name);
    this->updateId(id);

    this->licenseId = licenseId;
    this->experience = experience;
    this->authority = authority;

    listCommanders.push_back(this);
}

int Commander::getLicenseId()
{
    std::cout << this->licenseId;
    return this->licenseId;
}
void Commander::setlicenseId(int licenseId)
{
    this->licenseId = licenseId;
}

int Commander::getExperience()
{
    return this->experience;
}
void Commander::setExperience(int experience)
{
    this->experience = experience;
}

void Commander::setAuthority(int authority)
{
    this->authority = authority;
}


std::vector<Commander *> Commander::listCommanders;
Commander *Commander::assignCommander(int travelId)
{
    int allotted = false;

    while (allotted == false)
    {
        int k = rand() % listCommanders.size();
        if ((*(listCommanders[k])).allottedTravels.count(travelId) == 0)
        {
            (*(listCommanders[k])).allottedTravels.insert(travelId);
            allotted = true;
            return (listCommanders[k]);
        }
    }
}