//
// Created by Jose Lara on 5/25/25.
//

#ifndef ROOM_LOGISTICS_H
#define ROOM_LOGISTICS_H
#include "registration.h"
#include <string>

#endif //ROOM_LOGISTICS_H

const int ACUTE_CARE_ONE = 10;
const int ACUTE_CARE_TWO= 11;
const int ACUTE_CARE_THREE = 9;

class Logistics: public Patient {
    //set up emergency room array
private:
   string a_side[ACUTE_CARE_ONE];
    string b_side[ACUTE_CARE_TWO];
    string c_side[ACUTE_CARE_THREE];

public:

    //create the default constructor
    Logistics();

    void availableRooms();
    void insertPatient();


};