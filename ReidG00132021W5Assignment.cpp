#include <iostream>
using namespace std;

const int THRESHOLD = 12;

// Structure to hold the different values in Time
struct Time {
    int hours;
    string meridiem;
    string minutes;
};
Time Time24;
Time Time12;

int menu() {

    int choice;
    cout << "Choose a Time Conversion : " << endl;
    cout << "(1) Convert 24-hour notation to 12-hour notation." << endl;
    cout << "(2) Convert 12-hour notation to 24-hour notation." << endl;
    cout << "(3) to quit." << endl;

    cin >> choice;

    return choice;

}

void get24Time() {

    int hours = 0;
    string mins;
    char col;
    cout << "Enter 24hr time (hh:mm): ";
    cin >> hours >> col >> mins;

    // Initialize struct objects
    Time24.hours = hours;
    Time24.minutes = mins;

}

void get12Time() {

    int hours = 0;
    string mins, meridiem;
    char col;
    cout << "Enter 12hr time (hh:mm AM/PM): ";
    cin >> hours >> col >> mins >> meridiem;

    // Initialize struct objects
    Time12.hours = hours;
    Time12.minutes = mins;
    Time12.meridiem = meridiem;

}
//Convert 24hr format --> 12hr format
void convert24to12(struct Time T24) {

    cout << "In 12 hour format -" << endl;

    // Check the hours in the 24hr format
    if (T24.hours <= 11) {
        if (T24.hours == 0) {
            Time12.hours = 12;
        }
        Time12.hours = T24.hours;
        Time12.meridiem = "AM";
        cout << Time12.hours << ":" << T24.minutes << Time12.meridiem << endl;
    }
    else if (T24.hours <= 23) {
        if (T24.hours == 12) {
            Time12.hours = T24.hours;
        }
        else {
            Time12.hours = T24.hours - THRESHOLD;
        }
        Time12.meridiem = "PM";
        cout << Time12.hours << ":" << T24.minutes << Time12.meridiem << endl;
    }

}
//Convert 12hr format --> 24hr format
void convert12to24(struct Time T12) {

    cout << "In 24 hour format -" << endl;

    // Use the Meridiem to direct the flow
    if (T12.meridiem == "am" || T12.meridiem == "AM") {
        if (T12.hours == 12) {
            Time24.hours = 00;
        }
        else {
            Time24.hours = T12.hours;
        }
    }
    else if (T12.meridiem == "pm" || T12.meridiem == "PM") {
        if (T12.hours == 12) {
            Time24.hours = 12;
        }
        else {
            Time24.hours = T12.hours + THRESHOLD;
        }
    }

    cout << Time24.hours << ":" << T12.minutes << endl;

}

int main() {

    int choice;

    switch (menu()) {
        case 1:
            get24Time();
            convert24to12(Time24);
            break;
        case 2:
            get12Time();
            convert12to24(Time12);
            break;
        case 3:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Wrong selection" << endl;

    }

}