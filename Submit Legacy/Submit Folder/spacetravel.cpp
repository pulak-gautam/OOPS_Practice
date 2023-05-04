#include "spacetravel.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

spaceTravel::spaceTravel()
{
    std::cout << "Default Constructor" << std::endl;
}
spaceTravel::spaceTravel(Passenger p, int travelDate)
{
    Passenger dummy("dummy", 000);
    std::fill_n(std::back_inserter(this->travelList), 1000, dummy);

    std::cout << "HELLOEVERYONE";
    this->travelId = travelDate * 100 + travelDate % 2 * 10 + 1;
    (this->travelList)[0] = p;
    this->size = 1;

    this->commander = Commander::assignCommander(this->travelId);
    this->astronaut = Astronaut::assignAstronaut(this->travelId);
}

void spaceTravel::addTraveller(Passenger t)
{
    if (size > 8)
    {
        std::cerr << "This Travel has already reached its Maximum Occupancy" << std::endl;
    }
    else
    {
        travelList[size] = t;
        this->size = this->size + 1;
    }
}
void spaceTravel::listTravellers()
{
    std::cout << "\n-----+-----+-----\n";
    std::cout << "Passengers:-\n";

    for (int i = 0; i < this->size; i++)
    {
        std::cout << "Name : " << (travelList[i]).getName() << " ID : " << (travelList[i]).getId() << std::endl;
    }
    std::cout << "Astronaut:-\n";
    std::cout << "Name : " << (*(this->astronaut)).getName() << " ID : " << (*(this->astronaut)).getId();

    std::cout << "\nCommander:-\n";
    std::cout << "Name : " << (*(this->commander)).getName() << " ID : " << (*(this->commander)).getId();

    std::cout << "\n-----+-----+-----\n";
}

void spaceTravel::setAstronautId(Astronaut *a)
{
    this->astronaut = a;
}
void spaceTravel::setCommanderId(Commander *c)
{
    this->commander = c;
}

std::map<int, spaceTravel> spaceTravel::travels;