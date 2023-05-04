#include "planet.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

/*PLANETS' SPECIFICATIONS*/
// helper class for designating coordinates to planets

coordinate::coordinate(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

// Planet::Planet();
Planet::Planet(int x, int y, int z)
{
    this->positionX = x;
    this->positionY = y;
    this->positionZ = z;
}
coordinate Planet::getCoordinates()
{
    return coordinate(positionX, positionY, positionZ);
}
double Planet::distance(Planet destination)
{
    return sqrt(pow((this->positionX - destination.positionX), 2) + pow((this->positionY - destination.positionY), 2) + pow((this->positionZ - destination.positionZ), 2));
}


