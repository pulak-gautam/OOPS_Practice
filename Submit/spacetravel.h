#ifndef SPACETRAVEL_H
#define SPACETRAVEL_H

// #include "passenger.h"
#include "astronaut.h"
#include "commander.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class Passenger;
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
    spaceTravel(Passenger p, int travelDate, int sourceX, int destinationX, int sourceY, int destinationY, int sourceZ, int destinationZ);

    void addTraveller(Passenger t);
    void listTravellers();

    void setAstronautId(Astronaut *a);
    void setCommanderId(Commander *c);
};

#endif