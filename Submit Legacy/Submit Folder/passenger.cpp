#include "passenger.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

Passenger::Passenger(std::string name, int travellerId)
{
    this->updateName(name);
    this->updateId(travellerId);
}

// Passenger::
