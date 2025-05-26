

#ifndef STAFF_MANAGER_H
#define STAFF_MANAGER_H


//              C R E A T E         C L A S S




class Staff {
    /*private encapsulation is going to have the following
     *1.)Employee Name
     *2.)Employee ID
     *3.)Employee Role
     *4.)Staff vector
     */
private:
    std::string name;
    int id;
    std::string role;
    std::vector<Staff> staff;


public:
    //create the default constructor
    Staff();

    //setters
    void setName();
    void setId();
    void setRole();

    //create the getter constructers
    std::string getName();
    int getId();
    std::string getRole();

    //utility
    void display();
    void addStaff();
    bool verifyAdmin(std::string usr_input,std::string usr_pw);

};



#endif //REGISTRATION_H