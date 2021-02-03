#include "passenger.h"
using namespace std;

//Constructor for passenger
passenger::passenger(string name, string passportNumber, string contactNumber, int milesAccountNumber, int milesTraveled){
    this->name = name;
    this->passportNumber = passportNumber;
    this->contactNumber = contactNumber;
    this->milesAccountNumber = milesAccountNumber;
    this->milesTraveled = milesTraveled;
}

//Function to get name
string passenger::getName() {
    return name;
}

//Function to get passport number
string passenger::getPassportNumber() {
    return passportNumber;
}

//Function to get miles account number
int passenger::getMilesAccountNumber(){
    return milesAccountNumber;
}

//Function to get distance travelled
int passenger::getMilesTraveled(){
    return milesTraveled;
}

//Function to get contact number
string passenger::getContactNumber(){
    return contactNumber;
}

//Function to add distance travelled
int passenger::addMiles(int miles) {
    milesTraveled = milesTraveled + miles;
    return milesTraveled;
}

//Function to minus distance travelled
int passenger::minusMiles(int miles) {
    milesTraveled = milesTraveled - miles;
    return milesTraveled;
    {}}

//Function to string
void passenger::toString(){
    cout << getName() + " " + getPassportNumber() << " " << getContactNumber();
}

//Function to start main UI
void passenger::startup(){
    clearvector();
    readfromdatabase();
    cout << vectorofpassenger.size() <<endl;
    header();
    cout << "a) Login \n" <<
            "b) Sign Up \n" <<
            "c) Quit \n"
            "Please choose an action: ";
    cin >> choice;
    cout << endl;
    if (choice == 'a' || choice == 'A'){
        login();

    }else if (choice == 'b' || choice == 'B'){
        signup();

    }else if (choice == 'c' || choice == 'C'){
        writetodatabase();
        cout << "See you next time!" << endl;
        exit(0);

    }else{
        cout << "Please try again!" << endl << endl;
        startup();
    }
}

//Write passenger data to text file
void passenger::writetodatabase() {
    ofstream writedata;
    writedata.open("passenger.txt");
            if (vectorofpassenger.size() != 0){
                for (int i = 0; i < vectorofpassenger.size(); i++) {
                    writedata << i+1 << "\n" << vectorofpassenger[i].getName() << "\n" << vectorofpassenger[i].getPassportNumber() << "\n"
                              << vectorofpassenger[i].getContactNumber() << "\n" << vectorofpassenger[i].getMilesAccountNumber()  << "\n" << vectorofpassenger[i].getMilesTraveled() << "\n";
                }
            }
    writedata.close();
}

//Read passenger data from text file
void passenger::readfromdatabase(){
    string temp_name, temp_passportNumber, temp_contactNumber, temp_milesAccountNumber, temp_milesTraveled, x;
    ifstream readdata("passenger.txt");
    getline(readdata, x);
        if (x == ""){}
        else{
            ifstream readdata("passenger.txt");
            while(readdata){
                getline(readdata, x);
                if (x == ""){
                    break;
                }
                else{
                        getline(readdata, temp_name);
                        getline(readdata, temp_passportNumber);
                        getline(readdata, temp_contactNumber);
                        getline(readdata, temp_milesAccountNumber);
                        getline(readdata, temp_milesTraveled);
                        int_temp_milesAccountNumber = stoi(temp_milesAccountNumber);
                        int_temp_milesTraveled = stoi(temp_milesTraveled);
                        this->passportNumber = temp_passportNumber;
                        vectorofpassenger.push_back(passenger(temp_name, temp_passportNumber, temp_contactNumber, int_temp_milesAccountNumber, int_temp_milesTraveled));
                    }
                }
        }
}

//Function to check duplicated passenger
void passenger::checkDuplicatedPassenger(string temp_name, string temp_passportNumber, string temp_contactNumber){
     bool foundDuplicated = false;
         for (int i = 0; i < vectorofpassenger.size(); ++i){
             if (vectorofpassenger[i].getName() == temp_name &&
                 vectorofpassenger[i].getPassportNumber() == temp_passportNumber &&
                 vectorofpassenger[i].getContactNumber() == temp_contactNumber) {
                 foundDuplicated = true;
             }
         }
         if (foundDuplicated == false){
             vectorofpassenger.push_back(passenger(temp_name, temp_passportNumber, temp_contactNumber, (100000 + (vectorofpassenger.size()+1)), 0));
             writetodatabase();
             cout << endl << "New passenger added!" << endl;
             startup();
         }
         else if (foundDuplicated == true){
             cout << endl << "User exists! Please proceed to login." << endl << endl;
             startup();
         }
}

//Function to check login user exists or not
void passenger::checkLoginPassenger(string temp_name, string temp_passportNumber){
    bool loginGranted = false;
    if (temp_name == "admin" && temp_passportNumber == "admin"){
        cout << "Welcome back, adminstrator." << endl;
        flight f;
        f.readfromdatabase();
        f.adminstartup();
    }
    else {
        for (int i = 0; i < vectorofpassenger.size(); ++i) {
            if (vectorofpassenger[i].getName() == temp_name &&
                vectorofpassenger[i].getPassportNumber() == temp_passportNumber) {

                loginGranted = true;

            }
        }
        if (loginGranted == true) {
            writetodatabase();
            cout << "Login success!" << endl;
            booking b;
            readfromdatabase();
            b.passPassenger(temp_name, passportNumber, int_temp_milesTraveled);
            b.startup();

        } else if (loginGranted == false){
            cout << "Please try again!" << endl << endl;
            startup();
        }
    }
}

//clear contents of passenger vector
void passenger::clearvector(){
    vectorofpassenger.clear();
}

//Heading of the program
void passenger::header(){
    cout << "----------------------------------------" << endl;
    cout << setw(32) << "FLIGHT MANAGEMENT SYSTEM" << endl;
    cout << "----------------------------------------" << endl;
}

//Function for passenger to sign up
void passenger::signup(){
    header();
    string temp_name, temp_passportNumber, temp_contactNumber;
    cout << "Insert name: ";
    cin >> temp_name;
    cout << "Insert passport number: ";
    cin >> temp_passportNumber;
    cout << "Insert contact number: ";
    cin >> temp_contactNumber;
    checkDuplicatedPassenger(temp_name, temp_passportNumber, temp_contactNumber);
}

//Function for passenger to log in
void passenger::login(){
    string temp_name, temp_passportNumber;
    cout << "Insert name: ";
    cin >> temp_name;
    cout << "Insert passport number: ";
    cin >> temp_passportNumber;
    cout << endl;
    checkLoginPassenger(temp_name, temp_passportNumber);
}