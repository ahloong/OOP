//
// Created by loong on 5/8/2019.
//

#ifndef ASSIGNMENT_BOOKING_H
#define ASSIGNMENT_BOOKING_H

#include <iostream>
#include <string>
#include <fstream>
#include "passenger.h"
#include "airline.h"
#include "flight.h"
#include <vector>
#include <iomanip>


using namespace std;

class booking {
private:
    //declaration of private variables
    vector<booking> vectorofbooking;
    int bookingNumber;
    string name;
    string passport;
    string flightNumber;
    int numberOfSeat;
    int remainingSeat;
    string departureTime;
    string departureAirport;
    string destinationAirport;
    int boardingGate;
    string passportNumber;
    int milesTraveled;


public:
    //declaration of constructor
    booking(){};
    booking(int bookingNumber, string flightNumber, int numberOfSeat, int remainingSeat, string departureTime, string departureAirport, string destinationAirport, int boardingGate);

    //declaration of public variables
    int temp_index;
    char choice;
    string temp_departureAirport;
    string temp_arrivalAirport;
    string temp_date;
    string temp_hour;
    string temp_minute;

    //declaration of public functions
    void passPassenger(string name, string passportNumber, int milesTraveled);
    void startup();
    bool repeat;
    void header();
    void bookflight();
    int gettime();
    void checkflight();
    void checkmiles();
    void pushvector(int travellingDistance, string passportNumber, int bookingNumber, string flightNumber, int numberOfSeat, int remainingSeat, string departureTime, string departureAirport, string destinationAirport, int boardingGate);
    int getvectorsize();
    string searchfromdatabase(string passportNumber) ;
    void writetodatabase(string passportNumber, int bookingNumber, string flightNumber);
};


#endif //ASSIGNMENT_BOOKING_H
