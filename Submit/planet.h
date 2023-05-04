#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

/*PLANETS' SPECIFICATIONS*/
// helper class for designating coordinates to planets
class coordinate
{
public:
    int x;
    int y;
    int z;

    coordinate(int x, int y, int z);
};

class Planet
{
public:
    int positionX;
    int positionY;
    int positionZ;

    // Planet();
    Planet(int x = 0, int y = 0, int z = 0);
    bool operator ==(const Planet& p);

    coordinate getCoordinates();
    double distance(Planet destination);
};


#endif