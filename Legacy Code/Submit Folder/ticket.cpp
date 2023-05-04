#include "ticket.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>


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
    std::cout << "$" << this->price << std::endl;
    return this->price;
}

// bool Ticket::operator==(const Ticket& t1){
//     return (this->source == t1.source) && 
// }

std::map<int, std::vector<Ticket *>> Ticket::ticketList;
std::map<int, std::vector<Passenger>> Ticket::passengerList;

void Ticket::bookTicket(Planet s, Planet d, Passenger p)
{
    int travelDate;
    std::cout << "Enter your preferred date of travel (in DDMMYYYY format without any spaces or characters),\n eg. 15th March 2023 would be => 15032023\n";
    std::cin >> travelDate;

    Ticket t(s, d, p, travelDate);

    // invalid attributes of booking (early date, etc.)
    if (t.getPrice() == -1)
    {
        std::cout << "Error" << std::endl;
        return;
    }

    if (Ticket::ticketList[travelDate].size() == 1)
    {
        spaceTravel s(p, travelDate);
        s.addTraveller((Ticket::passengerList[travelDate])[0]);

        spaceTravel::travels[travelDate] = s;
        (spaceTravel::travels[travelDate]).listTravellers();
    }
    else if (Ticket::ticketList[travelDate].size() > 1)
    {
        ((spaceTravel::travels))[travelDate];
    }

    Ticket::ticketList[travelDate].push_back(&t);
    Ticket::passengerList[travelDate].push_back(p);

    return;
}
