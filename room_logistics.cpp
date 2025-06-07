//
// Created by Jose Lara on 5/25/25.
//

#include "room_logistics.h"
#include <iostream>
#include <iomanip>


Logistics::Logistics() {
    cout <<" ";
}

bool Logistics::isPatientInAnyRoom(int patientFin) {
    for (int i = 0; i < ACUTE_CARE_ONE; ++i)
        if (a_side[i] == patientFin) return true;
    for (int i = 0; i < ACUTE_CARE_TWO; ++i)
        if (b_side[i] == patientFin) return true;
    for (int i = 0; i < ACUTE_CARE_THREE; ++i)
        if (c_side[i] == patientFin) return true;
    return false;
}

void Logistics::insertPatient(int patientFin) {
    if (isPatientInAnyRoom(patientFin)) {
        std::cout << "Error: Patient already assigned to a room.\n";
        return;
    }
    // Example: insert into first available slot in a_side
    for (int i = 0; i < ACUTE_CARE_ONE; ++i) {
        if (a_side[i] == 0) {
            a_side[i] = patientFin;
            std::cout << "Patient assigned to Acute Care 1, room " << (i+1) << ".\n";
            return;
        }
    }
    for (int i = 0; i < ACUTE_CARE_TWO; ++i) {
        if (b_side[i] == 0) {
            b_side[i] = patientFin;
            std::cout << "Patient assigned to Acute Care 2, room " << (i+10) << ".\n";
            return;
        }
    }
    std::cout << "No available rooms in Acute Care 1 & 2.\n";
}

void Logistics::availableRooms() {
    cout << "Acute care 1 available rooms:\n";
    for (int i = 0; i < ACUTE_CARE_ONE; ++i) {
        if (a_side[i] == 0) { // 0 means unassigned
            cout << "Room " << (i+1) << " is available\n";
        }
    }
    cout << "\nAcute care 2 available rooms:\n";
    for (int i = 0; i < ACUTE_CARE_TWO; ++i) {
        if (b_side[i] == 0) { // 0 means unassigned
            cout << "Room " << (i+11) << " is available\n";
        }
    }
    cout << "\nAcute care 3 available rooms:\n";
    for (int i = 0; i < ACUTE_CARE_THREE; ++i) {
        if (c_side[i] == 0) { // 0 means unassigned
            cout << "Room " << (i+31) << " is available\n";
        }
    }


}

int Logistics::displayPatientRoom(int patientFin) {
    for (int i = 0; i < ACUTE_CARE_ONE; ++i)
        if (a_side[i] == patientFin) {
            std::cout << "Patient with FIN " << patientFin << " is in Side A, Room " << (i + 1) << ".\n";
            return i;
        }
    for (int i = 0; i < ACUTE_CARE_TWO; ++i)
        if (b_side[i] == patientFin) {
            std::cout << "Patient with FIN " << patientFin << " is in Side B, Room " << (i + 11) << ".\n";
            return i;
        }
    for (int i = 0; i < ACUTE_CARE_THREE; ++i)
        if (c_side[i] == patientFin) {
            std::cout << "Patient with FIN " << patientFin << " is in Side C, Room " << (i + 31) << ".\n";
            return i;
        }
    std::cout << "Patient with FIN " << patientFin << " is not assigned to any room.\n";
}

