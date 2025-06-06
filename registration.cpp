//
// Created by Josel on 5/22/2025.
//

#include "registration.h"
#include "room_logistics.h"
#include <fstream>
#include <iostream>
#include <random>
#include <iomanip>



using namespace std;

//                          C R E A T E     D E F A U L T       C O N S T R U C T O R




Patient::Patient() {
    cout << " ";
}



//                          D E F I N E     S E T T E R S




//set the pts name
void Patient::setName() {
    cout << "Full Name:";
    getline(cin, name);
}


//set pts gender
void Patient::setGender() {
    cout << "Gender:";
    cin >> gender;
    while (!genderValid(gender)) {
        cout << "Invalid entry.\n";
        cout << "Gender:";
        cin >> gender;
    }
}

void Patient::setFin() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(40000, 49999);
    rand_fin = dist(gen);
    fin = rand_fin;
}

//set pts dob
void Patient::setBirthDate() {
   cout << "Month:";
    cin >> month;
    cout << "Day:";
    cin >> day;
    cout << "Year:";
    cin >> year;
    //verify that the date input is valid
    while (!calendar_verification(year, month, day)) {
        cout << "Invalid date";
        cout << "Month (1-12):";
        cin >> month;
        cout << "Day:";
        cin >> day;
        cout << "Year:";
        cin >> year;
    }
}


//randomly generate a number as FIN


//set the location to 0, which means waiting area
void Patient::setLocation() {
    cin.ignore();
    cout << "Patient Location:";
    getline(cin,pt_loc);

    // Parse the input
    std::istringstream iss(pt_loc);
    std::string prefix;
    int locationNum = 0;
    iss >> prefix >> locationNum;
    if (prefix == "ED" && locationNum >= 1 && locationNum <= 39) {
        pt_loc_num = locationNum;

    } else {
        cout << "Invalid location. Please enter as 'ED <number>' with number between 1 and 39." << std::endl;
        pt_loc_num = 0; // or handle as invalid
    }
}

void Patient::setProviderNotes() {
    cout << "Provider Notes:";
    getline(cin,notes);
}

//                                       D E F I N E     S E T T E R S



//                                      D E F I N E        G E T T E R S


string Patient::getProviderNotes() {
    return notes;
}

int Patient::getFin() {

    return fin;
}

//get the pts name
string Patient::getName() {
    return name;
}


//get the pts gender
char Patient::getGender() {
    return toupper(gender);
}


//get the pts dob
string Patient::getBirthDate() {
    std::ostringstream oss;
    oss << year << "-";
    // Add leading zero for month and day if needed
    if (month < 10) oss << '0';
    oss << month << "-";

    if (day < 10) oss << '0';
    oss << day;

    return oss.str();
}


string Patient::getLocation() {
    return pt_loc;
}

//add pt to vector
void Patient::addPatient(Logistics &logistics) {
    Patient p;
    cin.ignore();
    p.setName();
    p.setGender();
    p.setBirthDate();
    p.getAge();
    cin.ignore();
    p.setProviderNotes();
    // Assign patient to a room by FIN
    logistics.insertPatient(p.getFin());
    patients.push_back(p);
}



//display the patients info
void Patient::display( Logistics& logistics) {
    //check if the vector is empty
    if (patients.empty()) {
        cout << "No patients registered.\n";
        return;
    }

    // if the vector isnt empty, display the patients info by using for loop
    cout << "==============================\n";
    cout << setw(25) << "Patient Information" << endl;
    cout << "==============================\n";

    for (int i = 0; i < patients.size(); i++) {
        cout << "Name: " << patients[i].getName() << endl;
        cout << "Gender: " << patients[i].getGender() << endl;
        cout << "Date of Birth: " << patients[i].getBirthDate() << endl;
        cout << "Age: " << patients[i].getAge() << endl;
        cout << "FIN: " << patients[i].getFin() << endl;
        cout << "Location: " << logistics.displayPatientRoom(patients[i].getFin()) <<endl;
        cout << "Provider Notes: " << patients[i].getProviderNotes() << endl;
        cout << endl;
    }
}

//                                      D E F I N E        G E T T E R S



//                          D E F I N E     U T I L I T Y      F U N C T I O N S




//create a function to verify that the day input is valid for the month
bool Patient::calendar_verification(int year,int month,int day) {
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;

    int daysInMonth;

    switch (month) {
        case 2:
            daysInMonth = isLeapYear(year) ? 29 : 28;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
    }

    return day <= daysInMonth;
}



//create another function for leap year incase pt was born on a leap day
bool Patient:: isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}



//verify the gender is valid input
bool Patient::genderValid(char gender) {
    if (gender == 'M' || gender == 'm' || gender =='f' || gender=='F') return true;
    else {
        return false;
    }
}



//get the patients age by subtracting current year with their year born, this can still be worked on since it adds an extra year for people whos birthday hasnt passed yet
int Patient::getAge() {
    int age = CURRENT_YEAR - year;
    return age;
}


bool Patient::isPatientInAnyRoom() {

}





