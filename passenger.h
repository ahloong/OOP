//
// Created by loong on 19/8/2019.
//

#ifndef ASSIGNMENT_2_PASSENGER_H
#define ASSIGNMENT_2_PASSENGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include "booking.h"
#include "flight.h"
#include "person.h"

using namespace std;

class passenger:public person{

public:
    //declaration of public variables
    string passportNumber;
    int int_temp_milesAccountNumber, int_temp_milesTraveled;
    int milesTraveled;
    int milesAccountNumber;
    char choice;
    bool repeat;
    vector<passenger> vectorofpassenger;

    //declaration of constructor
    passenger(){};
    passenger(string name, string passportNumber, string contactNumber, int milesAccountNumber, int milesTraveled);

    //declaration of public functions
    string getName();
    string getPassportNumber();
    string getContactNumber();
    int addMiles(int miles);
    int minusMiles(int miles);
    int getMilesAccountNumber();
    int getMilesTraveled();
    void startup();
    void writetodatabase();
    void toString();
    void readfromdatabase();
    void checkDuplicatedPassenger(string temp_name, string temp_passportNumber, string temp_contactNumber);
    void checkLoginPassenger(string temp_name, string temp_passportNumber);
    void clearvector();
    void header();
    void signup();
    void login();
};


#endif //ASSIGNMENT_2_PASSENGER_H
