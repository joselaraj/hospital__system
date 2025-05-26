//
// Created by Josel on 5/23/2025.

#include <iostream>
#include "staff_manager.h"
#include <iomanip>
#include <string>
using namespace std;

const std::string admin_user = "josel";
const std::string admin_pass = "<levi1009>";

Staff::Staff() {
    cout <<"";
}

//              D E F I N E     S E T T E R S
void Staff::setName() {
    cout << "Full Name:";
    getline(cin, name);
}

void Staff::setId() {
    cout << "Staff ID:";
    cin >> id;
}

void Staff::setRole() {
    cin.ignore();
    cout << "Role:";
    getline(cin,role);
}

//          D E F I N E     G E T T E R S

string Staff::getName() {
    return name;
}

int Staff::getId() {
    return id;
}

string Staff::getRole() {
    return role;
}

//              D E F I N E     U T I L I T Y      F U N C T I O N S

void Staff::addStaff() {
    Staff s;
    cin.ignore();
    s.setName();
    s.setId();
    s.setRole();
    staff.push_back(s);
}

void Staff::display() {
    cout << "==============================\n";
    cout << setw(25) << "Staff Information" << endl;
    cout << "==============================\n";

    for (int i = 0; i < staff.size(); i++) {
        cout << "Name: " << staff[i].getName() << endl;
        cout << "Staff ID: " << staff[i].getId() << endl;
        cout << "Role: " << staff[i].getRole() << endl;
        cout << endl;
    }
}

bool Staff::verifyAdmin(string usr_input, string usr_pw) {
    if (usr_input == admin_user && usr_pw == admin_pass) return true;
    else return false;
}
