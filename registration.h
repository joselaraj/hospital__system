//
// Created by Josel on 5/22/2025.
//

#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace  std;


/*
The patient will first register, the registration process will follow:
1.)Patients Name
2.)Patients Date of birth
3.)Generate a FIN number
4.)Add into the vector (we will use a DB later on when I learn how to connect it)
 */
const int CURRENT_YEAR =2025;
class Patient {
private:
 string name;
 char gender;
 int month,day,year;
 long int fin;

public:
 vector<Patient> patients;
//create the default constructor
 Patient();



 //setters
 void setName();
 void setGender();
 void setBirthDate();
 void setFin();



 //create the getter constructers
 string getName();
 char getGender();
 string getBirthDate();
 int getFin();
 int getAge();


 //utility
 void display();
 void addPatient();
 bool calendar_verification(int year,int month,int day);
 bool isLeapYear(int year);
 bool genderValid(char gender);
 void savePatientsToFile(const std::string& filename) ;
};

#endif //REGISTRATION_H
