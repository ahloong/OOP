//
// Created by loong on 12/8/2019.
//
#include "booking.h"
using namespace std;

//Constructor for booking
booking::booking(int bookingNumber, string flightNumber, int numberOfSeat, int remainingSeat, string departureTime, string departureAirport, string destinationAirport, int boardingGate){
    this->bookingNumber = bookingNumber;
    this->name = name;
    this->passport = passport;
    this->flightNumber = flightNumber;
    this->numberOfSeat = numberOfSeat;
    this->remainingSeat = remainingSeat;
    this->departureTime = departureTime;
    this->departureAirport = departureAirport;
    this->destinationAirport = destinationAirport;
    this->boardingGate = boardingGate;
}


void booking::passPassenger(string name, string passportNumber, int milesTraveled){
    this->name = name;
    this->passportNumber = passportNumber;
    this->milesTraveled = milesTraveled;
}

//Startup UI for booking
void booking::startup() {
    do {
        header();
        cout << "a) Book for a flight \n" <<
             "b) Check flight booked \n" <<
             "c) Check miles traveled \n" <<
             "d) Logout \n"
             "Please choose an action: ";

        cin >> choice;
        cout << endl;

        if (choice == 'a' || choice == 'A') {
            repeat = false;
            bookflight();
        } else if (choice == 'b' || choice == 'B') {
            repeat = false;
            checkflight();
        } else if (choice == 'c' || choice == 'C') {
            repeat = false;
            checkmiles();
        } else if (choice == 'd' || choice == 'D') {
            repeat = false;
            passenger p;
            p.startup();
        } else{
            repeat = true;
        }
    }while(repeat == true);
}

//Heading for the program
void booking::header(){
    cout << "----------------------------------------" << endl;
    cout << setw(32) << "FLIGHT MANAGEMENT SYSTEM" << endl;
    cout << "----------------------------------------" << endl;
}

//Function for flight booking
void booking::bookflight(){
    if(searchfromdatabase(passportNumber)!="ERROR"){
        cout << "You already booked a flight, please contact admin!";
        return;
    }
    flight f;
    f.printFlightList();
    cout << "Which flight would you like to book: ";
    cin >> temp_index;
    cout << endl;

    f.getFlightData(passportNumber,temp_index);

}

    int booking::gettime(){
        time_t now = time(0);
        char time_now[10] = "";
        strftime (time_now, 10,"%H%M", localtime(&now));
        return atoi(time_now);
    }


    //Functions for check flight
void booking::checkflight() {
    string response;
    int time_h = gettime() / 100;
    int time_m = gettime() % 100;
    int depart_h;
    int depart_m;
    string temp_fn = searchfromdatabase(passportNumber);
    if (temp_fn == "ERROR") {
        cout << "You have no booked flight." << endl;
        return;
    }
    flight f;
    f.readfromdatabase();
    for (int i = 0; i < f.vectorofflight.size(); i++) {
        if (f.vectorofflight[i].flightNumber == temp_fn){
            cout  << "Flight Number: " << f.vectorofflight[i].flightNumber << "\nDeparture Time: " << f.vectorofflight[i].departureTime << " " << "\nDeparture Airport: " << f.vectorofflight[i].departureAirport << " " << "\nDestination: " << f.vectorofflight[i].destinationAirport << " " << "\nBoarding Gate: " << f.vectorofflight[i].boardingGate;
            depart_h = stoi(f.vectorofflight[i].getDepartureTime()) / 100;
            depart_m = stoi(f.vectorofflight[i].getDepartureTime()) % 100;
            break;
        }
    }
    cout << "\nDo you wish to check-in now? (y/n)";
    cin >> response;
    if(response=="y"){
        if((depart_h * 60 + depart_m) - (time_h * 60 + time_m) <= 30){
            cout << "Cannot check-in, you need to check in 30 minutes before flight";
            return;
        }
        cout << "Check in completed, wish you a good flight!";
        return;
    }
    else{
        cout << "OK! Remember to check-in 30 minutes before flight!";

        return;
    }
}

//Function to check distance passenger travelled so far
void booking::checkmiles(){
    cout << this->name << " traveled " << this->milesTraveled << " Miles" << endl ;
}

//Function to get flight data from flight class
void booking::pushvector(int travellingDistance, string passportNumber, int bookingNumber,string flightNumber, int numberOfSeat, int remainingSeat, string departureTime, string departureAirport, string destinationAirport, int boardingGate){
    passenger p;
    p.readfromdatabase();
    for (int i = 0; i < p.vectorofpassenger.size(); i++) {
        if(p.vectorofpassenger[i].getPassportNumber() == passportNumber){
            p.vectorofpassenger[i].milesTraveled += travellingDistance;
            break;
        }
   }
    p.writetodatabase();
    vectorofbooking.push_back(booking(bookingNumber, flightNumber, numberOfSeat, remainingSeat, departureTime, departureAirport, destinationAirport, boardingGate));
    cout<< "done" << endl;
    writetodatabase(passportNumber, bookingNumber, flightNumber);
}

//return size of vector to another class
int booking::getvectorsize(){
    return vectorofbooking.size();
}

string booking::searchfromdatabase(string passportNumber) {
    ifstream readdata("booking.txt");
    string x;
    string pn, bn, fn;
    while(1){
        getline(readdata, pn);
        getline(readdata, bn);
        getline(readdata, fn);
        getline(readdata, x);
        if(pn == passportNumber) return fn;
        if(x == "")break;
    }
    return "ERROR";
}

//Write booking data in to text file
void booking::writetodatabase(string passportNumber, int bookingNumber, string flightNumber) {
    ofstream writedata;
    writedata.open("booking.txt",fstream::app);
    writedata << passportNumber << "\n" << bookingNumber << "\n" << flightNumber << "\n";
    writedata.close();
}

