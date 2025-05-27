//
// Created by Jose Lara on 5/25/25.
//

#include "room_logistics.h"

#include <iostream>
#include <iomanip>


Logistics::Logistics() {

}

void Logistics::availableRooms() {
    cout << "==============================\n";
    cout << setw(20) << "Acute care 1" << endl;
    cout << "==============================\n";

    for (int i = 0; i < 10; i++) {
        cout << "Room " << i+1 << endl;
    }
}