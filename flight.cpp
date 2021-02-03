//
// Created by loong on 12/8/2019.
//
#include "flight.h"
using namespace std;

//Temporary variable used by functions
    char choice;
    int temp_index;
    string temp_flightNumber;
    string temp_travelingDistance;
    string temp_numberOfSeat;
    string temp_remainingSeat;
    string temp_departureTime;
    string temp_departureAirport;
    string temp_destinationAirport;
    string temp_boardingGate;
    double double_temp_travelingDistance;
    int int_temp_numberOfSeat, int_temp_remainingSeat, int_temp_boardingGate;
    bool repeat = true;

//Constructor for flight class
flight::flight(string flightNumber, double travelingDistance, int numberOfSeat, int remainingSeat, string departureTime, string departureAirport, string destinationAirport, int boardingGate){
    this->flightNumber = flightNumber;
    this->travelingDistance = travelingDistance;
    this->numberOfSeat = numberOfSeat;
    this->remainingSeat = remainingSeat;
    this->departureTime = departureTime;
    this->departureAirport = departureAirport;
    this->destinationAirport = destinationAirport;
    this->boardingGate = boardingGate;
}

//Function to get flight number
string flight::getFlightNumber(){
    return flightNumber;
}

//Function to get travel distance
double flight::getTravelingDistance(){
    return travelingDistance;
}

//Function to get number of seat
int flight::getNumberOfSeat(){
    return numberOfSeat;
}

//Function to get remaining seat
int flight::getRemainingSeat(){
    return remainingSeat;
}

//Function to get departure time
string flight::getDepartureTime() {
    return departureTime;
}

//Function to get departure airport
string flight::getDepartureAirport() {
    return departureAirport;
}

//Function to get destination airport
string flight::getDestinationAirport() {
    return destinationAirport;
}

//Function to get boarding gate
int flight::getBoardingGate() {
    return boardingGate;
}

//Function to set new flight number
void flight::setFlightNumber(string new_flightNumber) {
    flightNumber = new_flightNumber;
}

//Function to set new travel distance
void flight::setTravelingDistance(double new_travelingDistance) {
    travelingDistance = new_travelingDistance;
}

//Function to set new number of seat
void flight::setNumberOfSeat(int new_numberOfSeat) {
    numberOfSeat = new_numberOfSeat;
}

//Function to set new remaining seat
void flight::setRemainingSeat(int new_remainingSeat) {
    remainingSeat = remainingSeat - new_remainingSeat;
}

//Function to set new departure time
void flight::setDepartureTime(string new_departureTime) {
    departureTime = new_departureTime;
}

//Function to set new departure airport
void flight::setDepartureAirport(string new_departureAirport){
    departureAirport = new_departureAirport;
}

//Function to set new destination airport
void flight::setDestinationAirport(string new_destinationAirport) {
    destinationAirport = new_destinationAirport;
}

//Function to set new boarding gate
void flight::setBoardingGate(int new_boardingGate) {
    boardingGate = new_boardingGate;
}

//Startup UI for administrator
void flight::adminstartup(){
    repeat = true;
    do{
        header();
        cout << "a) Create a flight \n" <<
                "b) Edit a flight\n" <<
                "c) Cancel a flight \n" <<
                "d) Logout \n"
                "Please choose an action: ";


         cin >> choice;
         cout << endl;

         repeat = true;

         if (choice == 'a' || choice == 'A') {
             repeat = false;
             createFlight();
         } else if (choice == 'b' || choice == 'B') {
             repeat = false;
             editFlight();
         } else if (choice == 'c' || choice == 'C') {
             repeat = false;
             cancelFlight();
         } else if (choice == 'd' || choice == 'D') {
             repeat = false;
             writetodatabase();
             passenger p;
             p.startup();
         } else {
             repeat = true;
         }
     }while(repeat == true);
}

//Function to create flight
void flight::createFlight(){
    header();
    readfromdatabase();

    cout << "Insert flight number: ";
    cin >> temp_flightNumber;

    cout << "Insert traveling distance: ";
    cin >> temp_travelingDistance;
    double_temp_travelingDistance = stod(temp_travelingDistance);

    cout << "Insert number of seat: ";
    cin >> temp_numberOfSeat;
    int_temp_numberOfSeat = stoi(temp_numberOfSeat);

    cout << "Insert number of remaining seat: ";
    cin >> temp_remainingSeat;
    int_temp_remainingSeat = stoi(temp_remainingSeat);

    cout << "Insert departure time: ";
    cin >> temp_departureTime;

    cout << "Insert departure airport: ";
    cin >> temp_departureAirport;

    cout << "Insert destination airport: ";
    cin >>temp_destinationAirport;

    cout << "Insert boarding gate: ";
    cin >> temp_boardingGate;
    int_temp_boardingGate = stoi(temp_boardingGate);
    vectorofflight.push_back(flight(temp_flightNumber, double_temp_travelingDistance, int_temp_numberOfSeat, int_temp_remainingSeat, temp_departureTime, temp_departureAirport, temp_destinationAirport, int_temp_boardingGate));
    cout << "Flight created!" << endl << endl;

    adminstartup();
}

//Function to edit flight
void flight::editFlight() {
    //UI of edit flight
    header();
    readfromdatabase();
    cout << "Which flight would you like to edit?" << endl;
    for (int i = 0; i < vectorofflight.size(); ++i) {
        cout << i << ") " << vectorofflight[i].getFlightNumber() << " " << vectorofflight[i].getTravelingDistance()
             << " " << vectorofflight[i].getNumberOfSeat() << " " << vectorofflight[i].getRemainingSeat() << " "
             << vectorofflight[i].getDepartureTime() << " " << vectorofflight[i].getDepartureAirport() << " "
             << vectorofflight[i].getDestinationAirport() << " " << vectorofflight[i].getBoardingGate() << " " << endl;
    }
    cout << vectorofflight.size() << ") Cancel" << endl;
    cout << "Please choose an option : ";
    cin >> temp_index;
    cout << endl;

    //Admin choose what to edit
    if (temp_index > -1 && temp_index < vectorofflight.size()) {
        cout << "Edit: " << endl;
        cout <<
             "a) Flight number \n" <<
             "b) Traveling distance\n" <<
             "c) Number of seat\n" <<
             "d) Remaining seat\n" <<
             "e) Departure time\n" <<
             "f) Departure airport\n" <<
             "g) Destination airport\n" <<
             "i) Boarding Gate" << endl;

        cout << "Please choose an option: " << endl;
        cin >> choice;
        cout << endl;

        //Process of insert new data
        repeat = true;
        do {
            if (choice == 'a' || choice == 'A') {
                cout << "Insert flight number: ";
                cin >> temp_flightNumber;
                vectorofflight[temp_index].setFlightNumber(temp_flightNumber);
                cout << "Changes saved!" << endl;
                repeat = false;
            } else if (choice == 'b' || choice == 'B') {
                cout << "Insert traveling distance: ";
                cin >> temp_travelingDistance;
                double_temp_travelingDistance = stod(temp_travelingDistance);
                vectorofflight[temp_index].setTravelingDistance(double_temp_travelingDistance);
                cout << "Changes saved!" << endl;
                repeat = false;
            } else if (choice == 'c' || choice == 'C') {
                repeat = false;
                cout << "Insert number of seat: ";
                cin >> temp_numberOfSeat;
                int_temp_numberOfSeat = stoi(temp_numberOfSeat);
                vectorofflight[temp_index].setNumberOfSeat(int_temp_numberOfSeat);
                cout << "Changes saved!" << endl;

            } else if (choice == 'd' || choice == 'D') {
                repeat = false;
                cout << "Insert number of remaining seat: ";
                cin >> temp_remainingSeat;
                int_temp_remainingSeat = stoi(temp_remainingSeat);
                vectorofflight[temp_index].setRemainingSeat(int_temp_remainingSeat);
                cout << "Changes saved!" << endl;
            } else if (choice == 'e' || choice == 'E') {
                cout << "Insert departure time: ";
                cin >> temp_departureTime;
                vectorofflight[temp_index].setDepartureTime(temp_departureTime);
                cout << "Changes saved!" << endl;
                repeat = false;
            } else if (choice == 'f' || choice == 'F') {
                repeat = false;
                cout << "Insert departure airport: ";
                cin >> temp_departureAirport;
                vectorofflight[temp_index].setDepartureAirport(temp_departureAirport);
                cout << "Changes saved!" << endl;
            } else if (choice == 'g' || choice == 'G') {
                repeat = false;
                cout << "Insert destination airport: ";
                cin >> temp_destinationAirport;
                vectorofflight[temp_index].setDestinationAirport(temp_destinationAirport);
                cout << "Changes saved!" << endl;
            } else if (choice == 'h' || choice == 'H') {
                repeat = false;
                cout << "Insert boarding gate: ";
                cin >> temp_boardingGate;
                int_temp_boardingGate = stoi(temp_boardingGate);
                vectorofflight[temp_index].setBoardingGate(int_temp_boardingGate);
                cout << "Changes saved!" << endl;
            } else if (temp_index == vectorofflight.size()) {
                adminstartup();
            } else {
                repeat = false;
                cout << "Please try again!";
            }
        } while (repeat == true);
    adminstartup();
    }
    else if(temp_index == vectorofflight.size()){
        adminstartup();
    }else{
        cout << "Please try again!" << endl;
    }
}

//Function to cancel flight
void flight::cancelFlight() {
    //UI to cancel flight
    header();
    cout << "Which flight would you like to cancel?" << endl;
    for (int i = 0; i < vectorofflight.size(); ++i) {
        cout << i << ") " << vectorofflight[i].getFlightNumber() << " " << vectorofflight[i].getTravelingDistance()
             << " " << vectorofflight[i].getNumberOfSeat() << " " << vectorofflight[i].getRemainingSeat() << " "
             << vectorofflight[i].getDepartureTime() << " " << vectorofflight[i].getDepartureAirport() << " "
             << vectorofflight[i].getDestinationAirport() << " " << vectorofflight[i].getBoardingGate() << " " << endl;
    }
    cout << vectorofflight.size() << ") Cancel" << endl;
    cout << "Please choose an option: ";
    cin >> temp_index;

    //Process of canceling flight
    if (temp_index > -1 && temp_index < vectorofflight.size()){
        vectorofflight.erase(vectorofflight.begin() + temp_index);
        cout << "Flight canceled!" << endl;
        adminstartup();
    }
    else{
        adminstartup();
    }
}

//Write flight data to text file
void flight::writetodatabase() {
    ofstream writedata;
    writedata.open("flight.txt");
    if (vectorofflight.size() > 0){
        for (int i = 0; i < vectorofflight.size(); ++i) {
            writedata << i+1 << "\n" << vectorofflight[i].getFlightNumber() << "\n" << vectorofflight[i].getTravelingDistance() << "\n"
                      << vectorofflight[i].getNumberOfSeat() << "\n" << vectorofflight[i].getRemainingSeat() << "\n" << vectorofflight[i].getDepartureTime() << "\n" << vectorofflight[i].getDepartureAirport() << "\n" << vectorofflight[i].getDestinationAirport() << "\n" << vectorofflight[i].getBoardingGate() << "\n";
        }
    }
    writedata.close();
}

//Read flight data from text file
void flight::readfromdatabase(){
    string x, string_temp_travelingDistance, string_temp_numberOfSeat, string_temp_remainingSeat, string_temp_boardingGate;
    ifstream readdata("flight.txt");
    getline(readdata, x);
    if (x == ""){}
    else{
        ifstream readdata("flight.txt");
        while(readdata){
            getline(readdata, x);
            if (x == ""){
                break;
            }
            else{
                getline(readdata, temp_flightNumber);
                getline(readdata, string_temp_travelingDistance);
                getline(readdata, string_temp_numberOfSeat);
                getline(readdata, string_temp_remainingSeat);
                getline(readdata, temp_departureTime);
                getline(readdata, temp_departureAirport);
                getline(readdata, temp_destinationAirport);
                getline(readdata, string_temp_boardingGate);
                double_temp_travelingDistance = stod(string_temp_travelingDistance);
                int_temp_numberOfSeat = stoi(string_temp_numberOfSeat);
                int_temp_remainingSeat = stoi(string_temp_remainingSeat);
                int_temp_boardingGate = stoi(string_temp_boardingGate);


                vectorofflight.push_back(flight(temp_flightNumber, double_temp_travelingDistance, int_temp_numberOfSeat, int_temp_remainingSeat, temp_departureTime, temp_departureAirport, temp_destinationAirport, int_temp_boardingGate));
            }
        }

    }
}

//Heading for the program
void flight::header(){
    cout << "----------------------------------------" << endl;
    cout << setw(32) << "FLIGHT MANAGEMENT SYSTEM" << endl;
    cout << "----------------------------------------" << endl;
}

//Function to print all available flight to UI
void flight::printFlightList() {
    header();
    readfromdatabase();
    cout << "Which flight would you like to book?" << endl;
    for (int i = 0; i < vectorofflight.size(); ++i) {
        cout << i << ") " << "Flight Number: " << vectorofflight[i].getFlightNumber() << " " <<  "\nTravelling Distance: " << vectorofflight[i].getTravelingDistance()
             << " " << "\nNumber Of Seats: " << vectorofflight[i].getNumberOfSeat() << " " << "\nRemaining Seats: " << vectorofflight[i].getRemainingSeat() << " "
             << "\nDeparture Time: " << vectorofflight[i].getDepartureTime() << " " << "\nDeparture Airport: " << vectorofflight[i].getDepartureAirport() << " "
             << "\nDestination Airport: " << vectorofflight[i].getDestinationAirport() << " " << "\nBoarding Gate:  " << vectorofflight[i].getBoardingGate() << " \n\n\n" << endl;
    }

}

//Return flight data chosen to another class
void flight::getFlightData(string passportNumber, int i){
    booking b;
    b.pushvector(vectorofflight[i].getTravelingDistance() ,passportNumber, (90000+b.getvectorsize()), vectorofflight[i].getFlightNumber(), vectorofflight[i].getNumberOfSeat(), vectorofflight[i].getRemainingSeat(), vectorofflight[i].getDepartureTime(), vectorofflight[i].getDepartureAirport(), vectorofflight[i].getDestinationAirport(), vectorofflight[i].getBoardingGate());
}