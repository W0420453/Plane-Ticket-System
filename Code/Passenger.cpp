#include <iostream>
#include "Person.cpp"

class Passenger : public Person { 

    public:

    //passenger knows its own seat number, what plane its on and potential luaggage later on.
    int seatNumber;
    string sectionName;

    public:
    
    //constructor
    Passenger(int seatNumber) : Person() {
        this -> firstName = "";
        this -> lastName = "";
        this -> day = 0;
        this -> month = 0;
        this -> year = 0;
        this -> seatNumber = seatNumber;
    }

    Passenger() : Person(){

    }

    //setter for seat number
    void SetSeatNumber(int seatNumber) {
        this -> seatNumber = seatNumber;
    }

    //getter for seat number
    int GetSeatNumber() {
        return this -> seatNumber;
    }

    //set sectionname
    void SetSectionName(string sectionName) {
        this -> sectionName = sectionName;
    }
};