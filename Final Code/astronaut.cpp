#include "astronaut.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

Astronaut::Astronaut(std::string name, int travellerId, int experience, int licenseId)
{
    this->updateName(name);
    this->updateId(travellerId);

    this->experience = experience;
    this->licenseId = licenseId;

    listAstronauts.push_back(this);
}
bool Astronaut::verifyAstronaut(int travelId){
    if(this->allottedTravels.count(travelId) == 0){
        return false;
    }
    return true;
}

int Astronaut::getExperience()
{
    std::cout << this->experience << std::endl;
    return this->experience;
}
void Astronaut::setExperience(int experience)
{
    this->experience = experience;
}


int Astronaut::getLicenseId()
{
    std::cout << this->licenseId << std::endl;
    return this->licenseId;
}
void Astronaut::setLicenseId(int licenseId)
{
    this->licenseId = licenseId;
}

std::vector<Astronaut *> Astronaut::listAstronauts;

Astronaut *Astronaut::assignAstronaut(int travelId)
{
    int allotted = false;

    while (allotted == false)
    {
        int k = rand() % listAstronauts.size();
        if ((*(listAstronauts[k])).allottedTravels.count(travelId) == 0)
        {
            (*(listAstronauts[k])).allottedTravels.insert(travelId);
            allotted = true;
            return (listAstronauts[k]);
        }
    }
}
