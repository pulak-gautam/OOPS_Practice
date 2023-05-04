
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
    //---------------------------------------+------------------------------+--------------------------------
    // MAIN FUNCTION

    // Helper Data Structures for Command Line Implementation
    // to access the exact passenger object queried
    std::map<std::string, Passenger> mp;
    std::map<std::string, Astronaut> ma;
    std::map<std::string, Commander> mc;

    // Creating Planet Objects
    Planet planet1(10, 20, 30);
    Moon moon; // moon and mars have default coordinates set already
    Mars mars;

    // Creating Passenger Objects (Hard-Coded)
    Passenger Andrew("Andrew", 210791); // Andrew with ID: 210791
    Passenger Rebecca("Rebecca", 210792);
    Passenger Varun("Varun", 200793);
    Passenger Sanket("Sanket", 210694);
    Passenger Krish("Krish", 21656);
    Passenger Soumya("Soumya", 210691);
    Passenger Karan("Karan", 180777);
    Passenger Harish("Harish", 190001);

    // Assigning keys to the map, so accessing the particular object is effecient (since map is implemented as a binary tree)
    mp["Andrew"] = Andrew;
    mp["Rebecca"] = Rebecca;
    mp["Varun"] = Varun;
    mp["Sanket"] = Sanket;
    mp["Krish"] = Krish;
    mp["Soumya"] = Soumya;
    mp["Karan"] = Karan;
    mp["Harish"] = Harish;

    // Creating Astronaut Objects
    Astronaut Jake("Jake", 120045, 15, 200001);
    Astronaut Vanshika("Vanshika", 130067, 10, 200002);

    ma["Jake"] = Jake;
    ma["Vanshika"] = Vanshika;

    // Creating Commander Objects
    Commander Pritam("Pritam", 110079, 1, 12, 100002);
    Commander Kush("Kush", 1100769, 1, 13, 100001);

    mc["Pritam"] = Pritam;
    mc["Kush"] = Kush;

    bool exit = false;
    // std::string readMe = "The code offers all the required implementations i.e.\n 1. A planet class with specific planets Mars and Moon as its subclasses, with its coordinate as attributes, and the corresponding helper functions along with a helper class - Coordinate\n2. A complete Traveller Class with all the required attributes, and subclasses - Passenger, Astronaut and Commander with all the required attributes\n3. A Ticket Class which is created as in when a ticket is booked, accompanied by all the necessary attributes and helper methods\n4. Finally, a Space Travel class whose object is only created if more than two queries of tickets for the same travel has been obtained";

    std::cout << "\t\t\t\t\t|| Welcome to Space Travel System ||\n\n";

    std::cout << "You can perform following functionalities on the \"command line\" and their respective string inputs, (refer to the *.h files to view the exaustive set of functionalities implemented):-\n";
    std::cout << "\nBONUS FEATURES IMPLEMENTED:\n1.Planet with Child Classes - Moon and Mars\n2.Commanders and Astronaut Schedules are always consistent and never conflict\n\n";
    std::cout << "Space Travel Ticket Logic: price = 10000 * (source.distance(destination)) / (travelDateDiff + 1)\n\n\n";

    std::cout << "(i) View List of (already Initialized 8) List of Registered Passengers - Enter character \"p\"\n";
    std::cout << "(ii) View List of (already Initialized 2) List of Registered Astronauts - Enter character \"a\"\n";
    std::cout << "(iii) View List of (already Initialized 2) List of Registered Commanders - Enter character \"c\"\n\n";
    std::cout << "(iv) Register a new Passenger - Enter string \"ip\"\n";
    std::cout << "(v) Register a new Astronauts - Enter string \"ia\"\n";
    std::cout << "(vi) Register a new Commanders - Enter string \"ic\"\n\n";
    std::cout << "(vii) Book Ticket for a Passenger - Enter string\"book\"\n";
    std::cout << "(viii) View Tickets (their respective details and attributes) of a Passenger - Enter string\"view_tickets\"\n";
    std::cout << "(ix) Update Ticket of a Passenger which was booked previously - Enter string \"update_ticket\"\n";
    std::cout << "(x) Cancel Ticket of a Passenger which was booked previously - Enter string \"cancel_ticket\"\n";
    std::cout << "(x) View Travellers' List for a particular Space Travel on a particular day (would be valid only if atleast three passengers have booked tickets for the same source/destination on the same day) - Enter string \"traveller_list\"\n";

    std::cout << "Enter string \"instructions\" to view the above functionalites vs prompt list again.\n";
    std::cout << "Enter string \"exit\" to exit the portal. Thank You!\n\n";
    
    std::string s;
    while (exit != true)
    {
        std::cout << "Enter string corresponding to the method you would like to invoke\n";
        std::cin >> s;

        if(s == "p"){
            std::cout << "Following list of Passengers has been registered (few have been by default in main.cpp):\n";
            for ( const auto &myPair : mp ) {
                std::cout << myPair.first << "\n";
            }
            std::cout << "\n";
        }

        else if(s == "a"){
            std::cout << "Following list of Astronauts has been registered (few have been by default in main.cpp):\n";
            for ( const auto &myPair : ma ) {
                std::cout << myPair.first << "\n";
            }
            std::cout << "\n";
        }

        else if(s == "c"){
            std::cout << "Following list of Commanders has been registered (few have been by default in main.cpp):\n";
            for ( const auto &myPair : mc ) {
                std::cout << myPair.first << "\n";
            }
            std::cout << "\n";
        }

        else if(s == "ip"){
            std::string name;
            int ID;

            std::cout << "\nEnter Name of Passenger :\n";
            std::cin >> name;

            std::cout << "\nEnter Passenger's ID :\n";
            std::cin >> ID;

            Passenger p(name, ID);
            mp[name] = p;

            std::cout << "Successfully Registered Passenger!" << std::endl;
        }

        else if(s == "ia"){
            std::string name;
            int ID;
            int licenseID;
            int exp;

            std::cout << "\nEnter Name of Astronaut :\n";
            std::cin >> name;

            std::cout << "\nEnter Astronaut's ID :\n";
            std::cin >> ID;

            std::cout << "\nEnter Astronaut's Experience (in years) :\n";
            std::cin >> exp;

            std::cout << "\nEnter Astronaut's License ID :\n";
            std::cin >> licenseID;


            Astronaut a(name, ID, exp, licenseID);
            ma[name] = a;

            std::cout << "Successfully Registered Astronaut!" << std::endl;
        }

        else if(s == "ic"){
            std::string name;
            int ID;
            int licenseID;
            int exp;

            std::cout << "\nEnter Name of Commander :\n";
            std::cin >> name;

            std::cout << "\nEnter Commander's ID :\n";
            std::cin >> ID;

            std::cout << "\nEnter Commander's Experience (in years) :\n";
            std::cin >> exp;

            std::cout << "\nEnter Commander's License ID :\n";
            std::cin >> licenseID;


            Commander c(name, ID, 1, exp, licenseID);
            mc[name] = c;

            std::cout << "Successfully Registered Commander!" << std::endl;
        }

        else if(s == "book"){
            std::string name;

            std::cout << "\nEnter Name of Passenger you would like to book ticket for (must be registered as a Passenger):\n";
            std::cin >> name;

            int xS, yS, zS;
            std::cout << "||Source Planet||";
            std::cout << "Enter x-coordinate of your source planet\n";
            std::cin >> xS;
            std::cout << "Enter y-coordinate of your source planet\n";
            std::cin >> yS;
            std::cout << "Enter z-coordinate of your source planet\n";
            std::cin >> zS;                

            int xD, yD, zD;
            std::cout << "||Destination Planet||";
            std::cout << "Enter x-coordinate of your destination planet\n";
            std::cin >> xD;
            std::cout << "Enter y-coordinate of your destination planet\n";
            std::cin >> yD;
            std::cout << "Enter z-coordinate of your destination planet\n";
            std::cin >> zD;                

            Planet source(xS, yS, zS); 
            Planet destination(xD, yD, zD); 

            Ticket::bookTicket(source, destination, &(mp[name]));

            /*To Book Travel b/w Mars and Moon*/
            // Mars source;
            // Moon destination;
            // Ticket::bookTicket(source, destination, &(mp[name]));
        }

        else if(s == "view_tickets"){
            std::string name;
            std::cout << "\nEnter Name of Passenger you would like to book ticket for (must be registered as a Passenger):\n";
            std::cin >> name;

            std::cout << (mp[name].listTickets).size();
            (mp[name]).viewTickets();
        }

        else if(s == "update_ticket"){
            std::string name;
            int prevDate;
            int newDate;

            std::cout << "\nEnter Name of Passenger you would like to update ticket for (must be registered as a Passenger, and the ticket must be booked sometime in past):\n";
            std::cin >> name;

            std::cout << "\nEnter Previous Date of Booking Ticket\n";
            std::cin >> prevDate;

            std::cout << "\nEnter New Date of Booking Ticket\n";
            std::cin >> newDate;

            int xS, yS, zS;
            std::cout << "\nEnter Coordinates of new source planet\n";
            std::cout << "Enter x-coordinate of your new source planet\n";
            std::cin >> xS;
            std::cout << "Enter y-coordinate of your new source planet\n";
            std::cin >> yS;
            std::cout << "Enter z-coordinate of your new source planet\n";
            std::cin >> zS;

            int xD, yD, zD;
            std::cout << "\nEnter Coordinates of new destination planet\n";
            std::cout << "Enter x-coordinate of your new destination planet\n";
            std::cin >> xD;
            std::cout << "Enter y-coordinate of your new destination planet\n";
            std::cin >> yD;
            std::cout << "Enter z-coordinate of your new destination planet\n";
            std::cin >> zD;  

            Planet source(xS, yS, zS);
            Planet destination(xD, yD, zD);

            Ticket::updateTicket(source, destination, &(mp[name]), prevDate, newDate);
        }

        else if(s == "cancel_ticket"){
            std::string name;
            int prevDate;

            std::cout << "\nEnter Name of Passenger you would like to cancel ticket for (must be registered as a Passenger, and the ticket must be booked sometime in past):\n";
            std::cin >> name;

            std::cout << "\nEnter Date of Booking Ticket";
            std::cin >> prevDate;

            mp[name].deleteTicket(prevDate);
        }

        else if(s == "traveller_list"){
            int date;
            std::cout << "\nEnter Date of Space Travel"; //assumption only one travel happens in a day
            std::cin >> date;
            (spaceTravel::travels[date]).listTravellers();
        }

        else if(s == "instructions"){
            std::cout << "You can perform following functionalities on the \"command line\" and their respective string inputs, (refer to the *.h files to view the exaustive set of functionalities implemented):-\n";
            std::cout << "\nBONUS FEATURES IMPLEMENTED:\n1.Planet with Child Classes - Moon and Mars\n2.Commanders and Astronaut Schedules are always consistent and never conflict\n\n";
            std::cout << "\nPrice of Ticket Logic: \nprice = 10000 * (source.distance(destination)) / (travelDateDiff + 1)\n";

            std::cout << "(i) View List of already Initialized List of Passengers - Enter character \"p\"\n";
            std::cout << "(ii) View List of already Initialized List of Astronauts - Enter character \"a\"\n";
            std::cout << "(iii) View List of already Initialized List of Commanders - Enter character \"c\"\n";
            std::cout << "(iv) Register a new Passenger - Enter string \"ip\"\n";
            std::cout << "(v) Register a new Astronauts - Enter string \"ia\"\n";
            std::cout << "(vi) Register a new Commanders - Enter string \"ic\"\n";
            std::cout << "(vii) Book Ticket for a Passenger - Enter string\"book\"\n";
            std::cout << "(viii) View Tickets (their respective details and attributes) of a Passenger - Enter string\"view_tickets\"\n";
            std::cout << "(ix) Update Ticket of a Passenger which was booked previously - Enter string \"update_ticket\"\n";
            std::cout << "(x) Cancel Ticket of a Passenger which was booked previously - Enter string \"cancel_ticket\"\n";
            
        }

        else if(s == "exit"){
            break;
        }

        else{
            std::cout << "\nINVALID OPTION SELECTED\n";
        }
    }
    
}