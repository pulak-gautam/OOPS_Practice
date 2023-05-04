
#include "planet.h"
#include "moon.h"
#include "mars.h"

#include "passenger.h"
#include "astronaut.h"
#include "commander.h"

#include "spacetravel.h"
#include "ticket.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

int main()
{
    /*Planet Class - Testing*/
    std::cout << "\n-----Planet Class - Testing-----\n";
    Moon moon;
    Mars mars;
    std::cout << moon.distance(mars) << std::endl;

    // /*Passenger Class - Testing*/
    std::cout << "\n-----Passenger Class - Testing-----\n";
    Passenger p("Pulak1", 210001);
    Passenger p1("Passenger2", 210001);

    // p.getName();
    p.updateName("Passenger1");
    // p.getName();
    // p.getId();
    // std::cout << p.verifyId(210001) << std::endl;
    // p.updateId(210790);
    // p.getId();
    // std::cout << "\n-----+-----+-----";

    /*Astronaut Class - Testing*/
    std::cout << "\n-----Astronaut Class - Testing-----\n";
    Astronaut a("Astronaut", 210002, 10, 210002);
    Astronaut a1("Astronaut", 210003, 10, 210003);
    // a.getExperience();
    // a.getLicenseId();
    // a.getId();
    // a.getName();
    // (Astronaut::listAstronauts)[0]->getName();
    // Astronaut *a1 = Astronaut::assignAstronaut(221);
    // for (auto i : a.allottedTravels)
    // {
    //     std::cout << i << std::endl;
    // }
    // std::cout << a.allottedTravels.empty();
    // std::cout << "\n-----+-----+-----";

    /*Commander Class - Testing*/
    std::cout << "\n-----Commander Class - Testing-----\n";
    Commander c("Commander", 210003, 10, 210003);
    Commander c1("Commander", 210004, 10, 210004);
    // c.getExperience();
    // c.getLicenseId();
    // c.getId();
    // c.getName();
    // (Commander::listCommanders)[0]->getName();
    // Commander *c1 = Commander::assignCommander(221);
    // for (auto i : c.allottedTravels)
    // {
    //     std::cout << i << std::endl;
    // }
    // std::cout << c.allottedTravels.empty() << std::endl;
    // std::cout << "\n-----+-----+-----";

    /*Space Travel Class - Testing*/
    std::cout << "\n-----Space Travel Class - Testing-----\n";
    // spaceTravel s(p, 22032023);
    // s.addTraveller(p);
    // s.addTraveller(p);
    // std::cout << s.size << std::endl;
    // s.listTravellers();
    // std::cout << "\n-----+-----+-----";

    /*Ticket Class - Testing*/
    // std::cout << "\n-----Ticket Class - Testing-----\n";
    // Ticket t(moon, mars, &p, 21032023);
    // std::cout << t.travellerName << std::endl;
    // t.getPrice();
    Ticket::bookTicket(mars, moon, p);
    Ticket::bookTicket(mars, moon, p);

    (spaceTravel::travels[22032023]).addTraveller(p1);
    (spaceTravel::travels[22032023]).setAstronautId(&a1);
    (spaceTravel::travels[22032023]).setCommanderId(&c1);

    (spaceTravel::travels[22032023]).listTravellers();
}