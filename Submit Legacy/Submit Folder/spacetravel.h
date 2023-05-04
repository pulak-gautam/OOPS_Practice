#ifndef SPACETRAVEL_H
#define SPACETRAVEL_H

#include "passenger.h"
#include "astronaut.h"
#include "commander.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class spaceTravel
{
private:
    Astronaut *astronaut;
    Commander *commander;
    long long int travelId;

public:
    int size;
    std::vector<Passenger> travelList;
    static std::map<int, spaceTravel> travels;

    spaceTravel();
    spaceTravel(Passenger p, int travelDate);

    void addTraveller(Passenger t);
    void listTravellers();

    void setAstronautId(Astronaut *a);
    void setCommanderId(Commander *c);
};

#endif