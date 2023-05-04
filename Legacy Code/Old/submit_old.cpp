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
    // std::vector<Ticket> tickets;

    std::string getName()
    {
        std::cout << this->name << std::endl;
        return this->name;
    }
    void updateName(std::string name)
    {
        this->name = name;
    }

    int getId()
    {
        std::cout << this->travellerId << std::endl;
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

    // Ticket getTicket()
    // {
    //     std::cout << "Following is the list of tickets :" << std::endl;
    //     for (int i = 0; i < tickets.size(); i++)
    //     {
    //         std::cout << "From " << tickets[0].source() << std::endl;
    //     }
    // }
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
    std::set<int> allottedTravels;

public:
    static std::vector<Astronaut*> listAstronauts;

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
        std::cout << this->experience;
        return this->experience;
    }
    void setExperience(int experience)
    {
        this->experience = experience;
    }

    int getLicenseId()
    {
        std::cout << this->licenseId;
        return this->licenseId;
    }
    void setLicenseId(int licenseId)
    {
        this->licenseId = licenseId;
    }

    static Astronaut* assignAstronaut(int travelId)
    {
        int allotted = false;
        Astronaut c;
        int x;

        for (int i = 0; i < listAstronauts.size(); i++)
        {
            if (allotted = true)
                break;
            if ((*(listAstronauts[i])).allottedTravels.empty())
            {
                (*(listAstronauts[i])).allottedTravels.insert(travelId);
                x = i;
                allotted = true;
            }
        }
        if (allotted == false)
        {
            while (allotted == false)
            {
                int k = rand() % listAstronauts.size();
                if ((*(listAstronauts[k])).allottedTravels.count(travelId) == 0)
                {
                    (*(listAstronauts[k])).allottedTravels.insert(travelId);
                    x = k;
                    allotted = true;
                }
            }
        }

        return (listAstronauts[x]);
    }
};
class Commander : public Traveller
{
private:
    int experience;
    int licenseId;
    int authority;
    std::set<int> allottedTravels;

public:
    static std::vector<Commander*> listCommanders;

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
        std::cout << this->experience;
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

    static Commander* assignCommander(int travelId)
    {
        int allotted = false;
        Commander c;
        int x;

        for (int i = 0; i < listCommanders.size(); i++)
        {
            if (allotted = true)
                break;
            if ((*(listCommanders[i])).allottedTravels.empty())
            {
                (*(listCommanders[i])).allottedTravels.insert(travelId);
                x = i;
                allotted = true;
            }
        }
        if (allotted == false)
        {
            while (allotted == false)
            {
                int k = rand() % listCommanders.size();
                if ((*(listCommanders[k])).allottedTravels.count(travelId) == 0)
                {
                    (*(listCommanders[k])).allottedTravels.insert(travelId);
                    x = k;
                    allotted = true;
                }
            }
        }

        return listCommanders[x];
    }
};

class spaceTravel
{
private:
    Astronaut* astronaut;
    Commander* commander;
    long long int travelId;
    std::vector<Passenger*> travelList;

public:
    static std::map<int, std::vector<spaceTravel *>> travels;

    spaceTravel(Passenger* p, int travelDate)
    {
        this->travelId = travelDate * 100 + travelDate % 2 * 10 + 1;
        (this->travelList).push_back(p);

        this->commander = Commander::assignCommander(this->travelId);
        this->astronaut = Astronaut::assignAstronaut(this->travelId);
    }

    void addTraveller(Passenger* t)
    {
        if (travelList.size() > 8)
        {
            std::cerr << "This Travel has already reached its Maximum Occupancy" << std::endl;
        }
        else
        {
            travelList.push_back(t);
        }
    }
    void listTravellers()
    {
        std::cout << "Passengers:-\n";
        for (Passenger* t : travelList)
        {
            std::cout << "Name : " << (*t).getName() << " ID : " << (*t).getId() << std::endl;
        }
        std::cout << "Astronaut:-\n";
        std::cout << "Name : " << (*astronaut).getName() << "ID : " << (*astronaut).getId() << std::endl;
    }

    void setAstronautId(Astronaut* a)
    {
        this->astronaut = a;
        // (*(this->astronaut)).updateId(a.getId());
        // (*(this->astronaut)).updateName(a.getName());
        // (*(this->astronaut)).setExperience(a.getLicenseId());
        // (*(this->astronaut)).setExperience(a.getExperience());
    }
    void setCommanderId(Commander* c)
    {
        this->commander = c;
        // (this->commander).updateId(c.getId());
        // (this->commander).updateName(c.getName());
        // (this->commander).setExperience(c.getLicenseId());
        // (this->commander).setExperience(c.getExperience());
    }

    // void updateAstronautId();
    // void updateCommanderId();
};

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
    static std::map<int, std::vector<Ticket*>> ticketList; //records info of all tickets booked on the platform
    static std::map<int, std::vector<Passenger*>> passengerList; //records info of all passengers who have booked tickets on the platform

    Ticket(Planet source, Planet destination, Traveller* p, int travelDate)
    {
        this->source = source;
        this->destination = destination;
        this->travellerName = (*p).getName();
        this->travellerId = (*p).getId();
        this->travelDate = travelDate;

        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);

        //(price_of_ticket) = distance(planets)/(delta(date) + 1)
        int curr_yr = 1900 + local_time->tm_year;
        int curr_month = 1 + local_time->tm_mon;
        int curr_day = local_time->tm_mday;

        // 2023
        // int travelDate = DDMMYYYY
        int travel_yr = travelDate % 10000;
        int travel_month = (travelDate / 10000) % 100;
        int travel_day = (travelDate / 1000000) % 100;

        int travelDateDiff = (travel_yr - curr_yr) * 365 + (travel_month - curr_month) * 30 + (travel_day - curr_day);
        if (travelDateDiff < 0)
        {
            std::cerr << "Invalid travel date. Kindly enter a valid date.";
            this->price = -1;
        }
        else
        {
            this->price = 10000 * (source.distance(destination)) / (travelDateDiff + 1);
        }
    }

    void bookTicket(Planet s, Planet d, Passenger* p)
    {
        int travelDate;
        std::cout << "Enter your preferred date of travel (in DDMMYYYY format without any spaces or characters), eg. 15th March 2023 would be => 15032023";
        std::cin >> travelDate;

        Ticket t(s, d, p, travelDate);

        // invalid attributes of booking (early date, etc.)
        if (t.price == -1)
        {
            return;
        }

        if (ticketList[travelDate].size() == 1)
        {
            // std::string n = (*((ticketList[travelDate])[0])).travellerName;
            // int i = (*((ticketList[travelDate])[0])).travellerId;
            // Passenger p1(n, i);
            // ticketList[travelDate].push_back(&t);
            spaceTravel s(p, travelDate);
            s.addTraveller((passengerList[travelDate])[0]);

            spaceTravel::travels[travelDate].push_back(&s);
        }
        else if (ticketList[travelDate].size() > 1)
        {
            (*((spaceTravel::travels[travelDate])[0])).addTraveller(p);
        }

        ticketList[travelDate].push_back(&t);
        passengerList[travelDate].push_back(p);

        return;
    }
};

int main()
{
    Planet a(1, 2, 1);
    Planet b(2, 2, 2);

    // std::cout << a.distance(b) << std::endl;

    Mars m;
    Moon M;
    // std::cout << m.distance(M) << std::endl;
    // m.getAtmosphereInfo();
    // m.getInhabitantsInfo();

    // M.getAtmosphereInfo();
    // M.getWaterInfo();

    Passenger t("Pulak", 210791);
    t.getName();
    t.updateName("Kush");
    t.getName();
    t.getId();
    std::cout << t.verifyId(210791) << std::endl;
    t.updateId(210790);
    t.getId();
}
