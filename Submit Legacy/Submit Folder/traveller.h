#ifndef TRAVELLER_H
#define TRAVELLER_H

#include "planet.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class Traveller
{
private:
    int travellerId;
    std::string name;

public:
    std::string getName();
    void updateName(std::string name);
    int getId();
    bool verifyId(int id);
    void updateId(int travellerId);
};

#endif