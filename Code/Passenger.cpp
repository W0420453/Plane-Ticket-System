#include <iostream>
#include "Person.cpp"

class Passenger : public Person { 

    public:

    //passenger knows its own seat number, what plane its on and potential luggage later on.

    //ACTUAL POSITION IN PLANE, NEEDS TO BE INCREMENTED BY 1 WHEN DISPLAYED
    int seatNumber;
    // Not set by default so that Passenger
    string sectionName;

    public:
    
    //constructor
    Passenger(int seatNumber) : Person() {
//        this -> firstName = "";
//        this -> lastName = "";
//        this -> day = 0;
//        this -> month = 0;
//        this -> year = 0;
        this -> seatNumber = seatNumber;

    }

    //Test Passenger
    Passenger(int seatNumber, bool isDefault) : Person() {
        this -> firstName = "asdf";
        this -> lastName = "asdf";
        this -> day = 0;
        this -> month = 0;
        this -> year = 1000;
        this -> seatNumber = seatNumber;
    }

    // Required to use the new Passenger[numberOfSeats] Call in Plane during construction, to allow for different sized arrays on creation
    Passenger() : Person(){ }

    //setter for seat number
    void SetSeatNumber(int seatNumber) {
        this -> seatNumber = seatNumber;
    }

    //getter for seat number | For use at a later date
    int GetSeatNumber() {
        return this -> seatNumber;
    }

    //set section name
    void SetSectionName(string sectionName) {
        this -> sectionName = sectionName;
    }

    string GetSectionName() {
        return this->sectionName;
    }
};