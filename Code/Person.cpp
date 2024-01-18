#include <iostream>
using namespace std;


class Person{
    public:
    string firstName;
    string lastName;
    int day;
    int month;
    int year;

    Person(){} // This is 100% required, for some reason
    Person(bool isDefault) 
    {
        if (isDefault)
        {
            this -> firstName = "";
            this -> lastName = ""; 
            this -> day = 0; 
            this -> month = 0; 
            this -> year = 0; 
        }
        else 
        {
            GetFullName();
            GetBirthday();
        }
    }

    // This is a copy constructor
    void GetFullName(){
        cout << "Enter your first name: ";
        //needs input validation
        cin >> this -> firstName;
        cout << "Enter your last name: ";
        //needs input validation
        cin >> this -> lastName;
    }

    // This is a copy constructor
    void GetBirthday(){
        cout << "Enter your birthday Month(mm): "; 
        //needs input validation
        cin >> this -> month;
        cout << "Enter your birthday Day(dd): ";
        //needs input validation
        cin >> this -> day;
        cout << "Enter your birthday Year(yyyy): ";
        //needs input validation
        cin >> this -> year;
    }
};