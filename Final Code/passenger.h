#ifndef PASSENGER_H
#define PASSENGER_H

#include "traveller.h"
#include "planet.h"
#include "ticket.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class Passenger : public Traveller
{
public:
    std::map<int, Ticket> listTickets;
    // Passenger();
    Passenger(std::string name = "", int travellerId = 0);
    
    void addTicket(Ticket t);
    void deleteTicket(int travelDate);
    bool verifyPassenger(Ticket t);
    void viewTickets();
};

#endif
