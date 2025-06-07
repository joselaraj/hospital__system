#include <iostream>
#include "registration.h"
#include "staff_manager.h"
#include "room_logistics.h"
#include <iomanip>
#include <string>
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
2.)The doctor will send the patient to appropriate testing such as x-ray,CT,MRI,Ultrasound,etc.
3.)The doctor will then determine if the patient will be admitted to one of the floors
4.)If the patient is moved to a room on the floor, the patients info will be changed to the new room
    else the patient will be discharged and sent home
*/

//Create a Menu Version
void Patient_Menu() {
    cout << "\n==============================\n";
    cout << setw(25) << "Emergency Department" << "\n";
    cout << "==============================\n";
    cout << setw(5) << "1) " << "Register\n";
    cout << setw(5) << "2) " << "View Patient Information\n";
    cout << setw(5) << "3) " << "Logout\n";
    cout << setw(5) << "4) " << "View available rooms\n";
    cout << setw(5) << "5) " << "Exit\n";
    cout << "\nEnter your choice: ";
}

void Staff_Menu() {
    cout << "==============================\n";
    cout << setw(20) << "Staff Menu" << "\n";
    cout << "==============================\n";
    cout << setw(5) << "1) " << "Login\n";
    cout << setw(5) << "2) " << "Create account\n";
    cout << setw(5) << "3) " << "Exit\n";
    cout << "Enter your choice: ";
}


int main() {

    /*
     *Create a loggedIn variable that keeps track of if the user is logged in or not
     *give the user a choice if they want to login or create an account/add patients
     *create a variable to break out of the do while loop
     *call in objects for the patient and staff
     *create a variable to store the user input of their username
     *create a variable to store the user input of their password
     */

    bool loggedIn = false;
    int user_choice;
    char runAgain;
    Patient manager;
    Staff admin;
    Logistics logistics;
    std::string user_input;
    std::string pass_input;

    //create a while loop to run the program
    do {
        //while loop for the staff menu, make sure only staff is logged in
        while (!loggedIn) {
            //display menu and then get user choice
            Staff_Menu();
            cin >> user_choice;
            //create a switch case to handle the user choice
            switch (user_choice) {
                case 1:
                    cout << "Login\n:";
                    cin.ignore();
                    cout << "Username:";
                    getline(cin, user_input);
                    cout << "Password:";
                    getline(cin, pass_input);
                    if (admin.verifyAdmin(user_input, pass_input)) {
                        cout << "Login Successful\n";
                        loggedIn = true;
                    } else {
                        cout << "Login Failed\n";
                    }
                    break;
                case 2:
                    admin.addStaff(); //create a function to add staff
                    break;
                case 3:
                    cout << "Exiting program...\n";
                    return 0;

                default:
                    cout << "Invalid choice\n";

                    break;
            }


        }

        // Logged-in menu loop
        while (loggedIn) {
            Patient_Menu();
            cin >> user_choice;
            switch (user_choice) {
                case 1:
                    manager.addPatient(logistics);
                    break;
                case 2:
                    manager.display(logistics);
                    break;
                case 3:  // Add logout option
                    loggedIn = false;
                    cout << "Logged out successfully.\n";
                    break;
                case 4:
                    logistics.availableRooms();
                    break;
                case 5:  // Add exit option
                    cout << "Exiting program...\n";
                    return 0;
                default:
                    cout << "Invalid choice\n";
                    break;
            }
        }

        cout << "Run again? (Y/N)";
        cin >> runAgain;


    }while (tolower(runAgain) == 'y');




    return 0;

}