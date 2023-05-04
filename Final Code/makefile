CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
 
main: main.o planet.o mars.o moon.o traveller.o passenger.o astronaut.o commander.o spacetravel.o ticket.o
	$(CC) $(CFLAGS) -o main main.o planet.o mars.o moon.o traveller.o passenger.o astronaut.o commander.o spacetravel.o ticket.o
 
main.o: planet.h moon.h mars.h passenger.h astronaut.h commander.h spacetravel.h ticket.h main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

planet.o: planet.h planet.cpp
	$(CC) $(CFLAGS) -c planet.cpp

mars.o: planet.h mars.cpp
	$(CC) $(CFLAGS) -c mars.cpp

moon.o: planet.h moon.cpp
	$(CC) $(CFLAGS) -c moon.cpp

traveller.o: planet.h traveller.cpp
	$(CC) $(CFLAGS) -c traveller.cpp

passenger.o: traveller.h passenger.cpp
	$(CC) $(CFLAGS) -c passenger.cpp

astronaut.o: traveller.h astronaut.cpp
	$(CC) $(CFLAGS) -c astronaut.cpp

commander.o: traveller.h commander.cpp
	$(CC) $(CFLAGS) -c commander.cpp

spacetravel.o: astronaut.h commander.h spacetravel.cpp
	$(CC) $(CFLAGS) -c spacetravel.cpp

ticket.o: planet.h astronaut.h commander.h spacetravel.h
	$(CC) $(CFLAGS) -c ticket.cpp
