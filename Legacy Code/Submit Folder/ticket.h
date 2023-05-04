#ifndef TICKET_H
#define TICKET_H

#include "planet.h"
#include "traveller.h"
#include "passenger.h"
#include "spacetravel.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class Ticket
{
private:
    int price;

public:
    Planet source;
    Planet destination;
    std::string travellerName;
    int travellerId;
    int travelDate;
    static std::map<int, std::vector<Ticket *>> ticketList;     // records info of all tickets booked on the platform
    static std::map<int, std::vector<Passenger>> passengerList; // records info of all passengers who have booked tickets on the platform
    static void bookTicket(Planet s, Planet d, Passenger p);

    Ticket(Planet source, Planet destination, Traveller p, int travelDate);
    // bool operator ==(const Ticket& t1);

    int getPrice();
};


#endif