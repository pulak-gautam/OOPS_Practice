// Space Travel System(STS)
/*
1. The traveller should be able to book a ticket to a planet from a source planet on a
specified date.
    (i)   Each ticket will have a default validity of ten years
    (ii)  The traveller should be able to book, delete and update any ticket
    (iii) The traveller should set his identification number
    (iv)  Each travel is assigned a unique identity number on creation
    (v)   Implement a functionality to print or view the ticket
    (vi)  Traveller name and travelled ID should be printed by calling getName() and getId() methods respectively.
2. The traveller should also have an optional choice of booking a return ticket
3. Three types of Travellers:
    (i)   Astronaut
          - infinite validity
          - Years of Experience
          - License ID (int/string, unique)
          - flying license
    (ii)  Commander
          - infinite validity
    (iii)  Passenger
          - authority
          - should be able to check upcoming travel details


*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>

/*PLANETS' SPECIFICATIONS*/
// helper class for designating coordinates to planets
class coordinate
{
public:
    int x;
    int y;
    int z;

    coordinate(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class Planet
{
public:
    int positionX;
    int positionY;
    int positionZ;

    Planet(int x = 0, int y = 0, int z = 0)
    {
        this->positionX = x;
        this->positionY = y;
        this->positionZ = z;
    }

    coordinate getCoordinates()
    {
        return coordinate(positionX, positionY, positionZ);
    }

    double distance(Planet destination)
    {
        return sqrt(pow((this->positionX - destination.positionX), 2) + pow((this->positionY - destination.positionY), 2) + pow((this->positionZ - destination.positionZ), 2));
    }
};

class Mars : public Planet
{
public:
    std::map<std::string, double> Atmosphere;
    double waterInfo;
    double inhabitants;

    // Mars' atmosphere is composed of 95.32% carbon dioxide, 2.7% nitrogen, 1.6% argon and 0.13% oxygen
    // fixed default coordinates as well
    Mars(int x = 49, int y = 52, int z = 64, double CO2_content = 95.32, double N2_content = 2.7, double Ar_content = 1.6, double O2_content = 0.13)
    {
        this->positionX = x;
        this->positionY = y;
        this->positionZ = z;

        this->waterInfo = 40;
        this->inhabitants = 14;

        Atmosphere["CO2"] = CO2_content;
        Atmosphere["N2"] = N2_content;
        Atmosphere["Ar"] = Ar_content;
        Atmosphere["O2"] = O2_content;
    }

    void getAtmosphereInfo()
    {
        std::cout << "Present Atmosphere Composition on Mars is as follows:\n";
        for (auto i : Atmosphere)
        {
            std::cout << i.first << " --> " << i.second << "%" << std::endl;
        }

        std::cout << "Please carry MARS (Mars' Atmosphere Respiratory Set) if you plan to visit Mars. Thank You!\n";
    }

    void getInhabitantsInfo()
    {
        std::cout << "\nPresent Inhabitant Population on Mars is " << inhabitants << " million" << std::endl;
    }

    void getWaterInfo()
    {
        std::cout << "\nPresent Water Availaibility on Mars is" << waterInfo << " per capita " << std::endl;
    }
};

class Moon : public Planet
{
public:
    std::map<std::string, double> Atmosphere;
    double waterInfo;

    // The atmospheric composition of the moon is about 33% neon, 33% helium and 33% hydrogen.
    // fixed default coordinates as well
    Moon(int x = 23, int y = 2, int z = 47, double Ne_content = 33, double He_content = 33, double H2_content = 33)
    {
        this->positionX = x;
        this->positionY = y;
        this->positionZ = z;

        this->waterInfo = 0.5;

        Atmosphere["Ne"] = Ne_content;
        Atmosphere["He"] = He_content;
        Atmosphere["H2"] = H2_content;
    }

    void getAtmosphereInfo()
    {
        std::cout << "\nPresent Atmosphere Composition on Moon is as follows:\n";
        for (auto i : Atmosphere)
        {
            std::cout << i.first << " --> " << i.second << "%" << std::endl;
        }
    }

    void getWaterInfo()
    {
        std::cout << "\nPresent Water Availaibility on Moon is " << waterInfo << " million litres " << std::endl;
        std::cout << "We apologize for the inconvinence. We are constantly working towards bringing water scarcity on Moon to an end. Thank You" << std::endl;
    }
};

class Traveller
{
private:
    int travellerId;
    std::string name;

public:
    std::string getName()
    {
        return this->name;
    }
    void updateName(std::string name)
    {
        this->name = name;
    }

    int getId()
    {
        return this->travellerId;
    }
    bool verifyId(int id)
    {
        return (id == this->travellerId);
    }
    void updateId(int travellerId)
    {
        this->travellerId = travellerId;
    }
};

class Passenger : public Traveller
{
public:
    Passenger(std::string name, int travellerId)
    {
        this->updateName(name);
        this->updateId(travellerId);
    }
};

class Astronaut : public Traveller
{
private:
    int licenseId;
    int experience;

public:
    std::set<int> allottedTravels;
    static std::vector<Astronaut *> listAstronauts;

    Astronaut(std::string name = "", int travellerId = 0, int experience = 0, int licenseId = 0)
    {
        this->updateName(name);
        this->updateId(travellerId);

        this->experience = experience;
        this->licenseId = licenseId;

        listAstronauts.push_back(this);
    }

    int getExperience()
    {
        std::cout << this->experience << std::endl;
        return this->experience;
    }
    void setExperience(int experience)
    {
        this->experience = experience;
    }

    int getLicenseId()
    {
        std::cout << this->licenseId << std::endl;
        return this->licenseId;
    }
    void setLicenseId(int licenseId)
    {
        this->licenseId = licenseId;
    }

    static Astronaut *assignAstronaut(int travelId);
};
std::vector<Astronaut *> Astronaut::listAstronauts;

Astronaut *Astronaut::assignAstronaut(int travelId)
{
    int allotted = false;

    while (allotted == false)
    {
        int k = rand() % listAstronauts.size();
        if ((*(listAstronauts[k])).allottedTravels.count(travelId) == 0)
        {
            (*(listAstronauts[k])).allottedTravels.insert(travelId);
            allotted = true;
            return (listAstronauts[k]);
        }
    }
}

class Commander : public Traveller
{
private:
    int experience;
    int licenseId;
    int authority;

public:
    std::set<int> allottedTravels;
    static std::vector<Commander *> listCommanders;

    Commander(std::string name = "", int id = 0, int authority = 0, int experience = 0, int licenseId = 0)
    {
        this->updateName(name);
        this->updateId(id);

        this->licenseId = licenseId;
        this->experience = experience;
        this->authority = authority;

        listCommanders.push_back(this);
    }

    int getLicenseId()
    {
        std::cout << this->licenseId;
        return this->licenseId;
    }
    void setlicenseId(int licenseId)
    {
        this->licenseId = licenseId;
    }

    int getExperience()
    {
        return this->experience;
    }
    void setExperience(int experience)
    {
        this->experience = experience;
    }

    void setAuthority(int authority)
    {
        this->authority = authority;
    }

    static Commander *assignCommander(int travelId);
};

std::vector<Commander *> Commander::listCommanders;
Commander *Commander::assignCommander(int travelId)
{
    int allotted = false;

    while (allotted == false)
    {
        int k = rand() % listCommanders.size();
        if ((*(listCommanders[k])).allottedTravels.count(travelId) == 0)
        {
            (*(listCommanders[k])).allottedTravels.insert(travelId);
            allotted = true;
            return (listCommanders[k]);
        }
    }
}

class spaceTravel
{
private:
    Astronaut *astronaut;
    Commander *commander;
    long long int travelId;

public:
    int size;
    std::vector<Passenger> travelList;
    static std::map<int, spaceTravel> travels;

    spaceTravel()
    {
        std::cout << "HELLO" << std::endl;
    }
    spaceTravel(Passenger p, int travelDate)
    {
        Passenger dummy("dummy", 000);
        std::fill_n(std::back_inserter(this->travelList), 1000, dummy);

        this->travelId = travelDate * 100 + travelDate % 2 * 10 + 1;
        (this->travelList)[0] = p;
        this->size = 1;

        this->commander = Commander::assignCommander(this->travelId);
        this->astronaut = Astronaut::assignAstronaut(this->travelId);
    }

    void addTraveller(Passenger t)
    {
        if (size > 8)
        {
            std::cerr << "This Travel has already reached its Maximum Occupancy" << std::endl;
        }
        else
        {
            travelList[size] = t;
            this->size = this->size + 1;
        }
    }
    void listTravellers()
    {
        std::cout << "\n-----+-----+-----\n";
        std::cout << "Passengers:-\n";

        for (int i = 0; i < this->size; i++)
        {
            std::cout << "Name : " << (travelList[i]).getName() << " ID : " << (travelList[i]).getId() << std::endl;
        }
        std::cout << "Astronaut:-\n";
        std::cout << "Name : " << (*(this->astronaut)).getName() << " ID : " << (*(this->astronaut)).getId();

        std::cout << "\nCommander:-\n";
        std::cout << "Name : " << (*(this->commander)).getName() << " ID : " << (*(this->commander)).getId();

        std::cout << "\n-----+-----+-----\n";
    }

    void setAstronautId(Astronaut *a)
    {
        this->astronaut = a;
    }
    void setCommanderId(Commander *c)
    {
        this->commander = c;
    }
};

std::map<int, spaceTravel> spaceTravel::travels;

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

    Ticket(Planet source, Planet destination, Traveller p, int travelDate)
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

    int getPrice()
    {
        std::cout << "$" << this->price << std::endl;
        return this->price;
    }
};

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

Passenger dummy("dummy", 000);

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
    
    // ((spaceTravel::travels[21032023])[0])->listTravellers();
}
