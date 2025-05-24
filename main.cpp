#include <iostream>
#include "registration.h"
#include <string>
#include <iomanip>
using namespace std;

/*
Author: Jose Lara
Date: 5/22/2025
Purpose: Create a Hospital system that allows you to create patient profiles.

The patient will first register, the registration process will follow:
1.)Patients Name
2.)Patients Date of birth
3.)Generate a FIN number
4.)Add into the vector (we will use a DB later on when I learn how to connect it)

5.)Patient will then be added to a queue
6.)Patients location will be set to waiting area

Once the patient is registered then they will be added into the Emergency Department (ED)
In the ED the following process will happen:
1.)The patient will be placed in a room/hallway
2.)The doctor will send the patient to appropriate testing such as x-ray,CT,MRI,Ultrasound,etc
3.)The doctor will then determine if the patient will be admitted to one of the floors
4.)If the patient is moved to a room on the floor, the patients info will be changed to the new room
    else the patient will be discharged and sent home
*/

//Create a Menu Version
void Menu() {
    cout << "\n==============================\n";
    cout << setw(25) << "Emergency Department" << "\n";
    cout << "==============================\n";
    cout << setw(5) << "1) " << "Register\n";
    cout << setw(5) << "2) " << "View Patient Information\n";
    cout << "Enter your choice: ";
}

int main() {
    int user_choice;
    char runAgain;
    Patient manager;

    do {
        Menu();
        cin >> user_choice;
        switch (user_choice) {
            case 1:
                manager.addPatient();
                break;
            case 2:
                manager.display();
                break;

            default:
                return 0;
        }
        cout << "Run again?";
        cin >> runAgain;
    }while (runAgain == 'y');

    return 0;
}