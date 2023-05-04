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

void Passenger::addTicket(Ticket t)
{
    (this->listTickets)[t.travelDate] = t;
}
void Passenger::deleteTicket(int travelDate){
    (this->listTickets).erase(travelDate);
}
bool Passenger::verifyPassenger(Ticket t)
{
    if((this->listTickets).count(t.travelDate) == 0){ //has no ticket of the same date
        return false;
    }
    else return (this->listTickets)[t.travelDate] == t; //checking credentials of passenger
}

void Passenger::viewTickets(){
    for (auto i : this->listTickets)
        (i.second).printTicket();
}