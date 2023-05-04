#include "ticket.h"
#include "passenger.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

Ticket::Ticket(){

}

Ticket::Ticket(Planet source, Planet destination, Traveller p, int travelDate)
{
    this->source = source;
    this->destination = destination;
    this->travellerName = (p).getName();
    this->travellerId = (p).getId();
    this->travelDate = travelDate;

    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    //(price_of_ticket) = distance(planets)/(delta(date) + 1)
    int curr_yr = 1900 + local_time->tm_year;
    int curr_month = 1 + local_time->tm_mon;
    int curr_day = local_time->tm_mday;

    // int travelDate = DDMMYYYY
    int travel_yr = travelDate % 10000;
    int travel_month = (travelDate / 10000) % 100;
    int travel_day = (travelDate / 1000000) % 100;

    int travelDateDiff = (travel_yr - curr_yr) * 365 + (travel_month - curr_month) * 30 + (travel_day - curr_day);

    if (travelDateDiff < 0)
    {
        std::cerr << "Invalid travel date. Kindly enter a valid date.\n";
        this->price = -1;
    }
    else
    {
        this->price = 10000 * (source.distance(destination)) / (travelDateDiff + 1);
    }
}

int Ticket::getPrice()
{
    // std::cout << "$" << this->price << std::endl;
    return this->price;
}

bool Ticket::operator==(const Ticket& t1){
    return ((this->source == t1.source) && (this->destination == t1.destination) && (this->travellerName == t1.travellerName) && (this->travellerId == t1.travellerId) && (this->travelDate == t1.travelDate));
}

std::map<int, std::vector<Ticket *>> Ticket::ticketList; // list of all tickets booked
std::map<int, std::vector<Passenger*>> Ticket::passengerList; // list of all passengers who booked tickets

void Ticket::bookTicket(Planet source, Planet destination, Passenger *p)
{
    int travelDate;
    std::cout << "Enter your preferred date of travel (in DDMMYYYY format without any spaces or characters),\n eg. 15th March 2023 would be => 15032023\n";
    std::cin >> travelDate;

    Ticket t(source, destination, *p, travelDate);

    // invalid attributes of booking (early date, etc.)
    if (t.getPrice() == -1)
    {
        std::cout << "Error" << std::endl;
        return;
    }
    std::cout << "\n|| The ticket-fee amount of $" << t.getPrice() << " would be payable||\n"; 

    if (Ticket::ticketList[travelDate].size() == 2)
    {
        spaceTravel s(*p, travelDate, source.positionX, destination.positionX, source.positionY, destination.positionY, source.positionZ, destination.positionZ);
        s.addTraveller(*(Ticket::passengerList[travelDate])[0]);
        s.addTraveller(*(Ticket::passengerList[travelDate])[1]);

        spaceTravel::travels[travelDate] = s;
        // (spaceTravel::travels[travelDate]).listTravellers();
    }
    else if (Ticket::ticketList[travelDate].size() > 2)
    {
        ((spaceTravel::travels))[travelDate];
    }

    Ticket::ticketList[travelDate].push_back(&t);
    Ticket::passengerList[travelDate].push_back(p);
    p->addTicket(t);

    return;
}

void Ticket::updateTicket(Planet s, Planet d, Passenger *p, int prevTravelDate, int updatedTravelDate){
    p->deleteTicket(prevTravelDate);
    Ticket t(s, d, *p, updatedTravelDate);
    p->addTicket(t);
}

void Ticket::printTicket(){

    std::cout << "\n-----+-----+-----\n";
    std::cout << "Source Planet Coordinates : " << "(" << (this->source).positionX << "," << (this->source).positionY << "," << (this->source).positionZ << ")" << std::endl;
    std::cout << "Destination Planet Coordinates : " << "(" << (this->destination).positionX << "," << (this->destination).positionY << "," << (this->destination).positionZ << ")" << std::endl;
    std::cout << "Traveller Name : " << this->travellerName << std::endl;
    std::cout << "Traveller ID : " << this->travellerId << std::endl;
    std::cout << "Travel Date (in DDMMYYYY format) : " << this->travelDate << std::endl;
    std::cout << "Price of Ticket : $" << this->getPrice() << std::endl;
    std::cout << "\n-----+-----+-----\n";
}
