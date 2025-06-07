//
// Created by Jose Lara on 5/25/25.
//

#ifndef ROOM_LOGISTICS_H
#define ROOM_LOGISTICS_H

#include "registration.h"
#include <string>



const int ACUTE_CARE_ONE = 10;
const int ACUTE_CARE_TWO= 11;
const int ACUTE_CARE_THREE = 9;

class Logistics: public Patient {
    //set up emergency room array
private:
   int a_side[ACUTE_CARE_ONE] = {0};
    int b_side[ACUTE_CARE_TWO] = {0};
    int c_side[ACUTE_CARE_THREE] ={0};

public:

    //create the default constructor
    Logistics();

    void availableRooms();
    void insertPatient(int patientFin);
    bool isPatientInAnyRoom(int patientFin); // Add this function
    int displayPatientRoom(int patientFin);

};

#endif //ROOM_LOGISTICS_H