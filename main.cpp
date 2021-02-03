#include <iostream>
#include <string>
#include "passenger.h"
#include "flight.h"
#include "booking.h"
#include "miles.h"
#include "flight.h"
#include <time.h>
using namespace std;

int main() {
    //Check current time, if time is not between 6am to 10pm
    time_t now = time(0);
    char time_now[10] = "";
    strftime (time_now, 10,"%H%M", localtime(&now));
    int time_h = atoi(time_now) / 100;
    int time_m = atoi(time_now) % 100;
    cout << time_h << time_m;

    //If not, exit
    if((time_h >= 22 && time_m >= 0) || (time_h < 6)) {
        cout << "SYSTEM CLOSED" << endl;
        return 0;
    }

    //else start the program
    passenger p;
    p.startup();
}