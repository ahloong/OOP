//
// Created by loong on 5/8/2019.
//

#ifndef ASSIGNMENT_FLIGHT_H
#define ASSIGNMENT_FLIGHT_H

#include "airline.h"
#include "passenger.h"
#include "booking.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

class flight{

public:
    //declaration of public variables
    string flightNumber;
    double travelingDistance;
    int numberOfSeat;
    int remainingSeat;
    string departureTime;
    string departureAirport;
    string destinationAirport;
    int boardingGate;
    vector<flight> vectorofflight;

    //declaration of constructors
    flight(){};
    flight(string flightNumber, double travelingDistance, int numberOfSeat, int remainingSeat, string departureTime, string departureAirport, string destinationAirport, int boardingGate);

    //declaration of public functions
    string getFlightNumber();
    double getTravelingDistance();
    int getNumberOfSeat();
    int getRemainingSeat();
    string getDepartureTime();
    string getDepartureAirport();
    string getDestinationAirport();
    int getBoardingGate();
    void setFlightNumber(string new_flightNumber);
    void setTravelingDistance(double new_travelingDistance);
    void setNumberOfSeat(int new_numberOfSeat);
    void setRemainingSeat(int new_remainingSeat);
    void setDepartureTime(string new_departureTime);
    void setDepartureAirport(string new_departureAirport);
    void setDestinationAirport(string new_destinationAirport);
    void setBoardingGate(int new_boardingGate);
    void createFlight();
    void editFlight();
    void cancelFlight();
    void startup();
    void adminstartup();
    void bookflight();
    void writetodatabase();
    void readfromdatabase();
    void header();
    void printFlightList();
    void getFlightData(string passportNumber, int i);
};


#endif //ASSIGNMENT_FLIGHT_H
