#ifndef PASSENGER_H
#define PASSENGER_H

#include "traveller.h"
#include "planet.h"
// #include "ticket.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class Passenger : public Traveller
{
    // std::vector<Ticket> listTickets;
public:
    Passenger(std::string name, int travellerId);
    
    // void addTicket(Ticket t);
    // void verifyPassenger(Ticket t);
};

#endif
