#include "traveller.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

std::string Traveller::getName()
{
    return this->name;
}
void Traveller::updateName(std::string name)
{
    this->name = name;
}
int Traveller::getId()
{
    return this->travellerId;
}
bool Traveller::verifyId(int id)
{
    return (id == this->travellerId);
}
void Traveller::updateId(int travellerId)
{
    this->travellerId = travellerId;
}
