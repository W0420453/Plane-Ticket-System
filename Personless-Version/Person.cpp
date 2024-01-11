#include <iostream>
using namespace std;


class Person{
    public:
    string firstName;
    string lastName;
    int day;
    int month;
    int year;


    Person() 
    {
        getFullName();
        getBirthday();
    }

    Person(String fName, String lName, int month,  int day, int year) 
    {
        this -> firstName = fName; 
        this -> lastName = lName;
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }

    void getFullName(){
        cout << "Enter your first name: ";
        cin >> this -> firstName;
        cout << "Enter your last name: ";
        cin >> this -> lastName;
    }

    void getBirthday(){
        cout << "Enter your birthday Month(mm): "; 
        cin >> this -> month;
        cout << "Enter your birthday Day(dd): ";
        cin >> this -> day;
        cout << "Enter your birthday Year(yyyy): ";
        cin >> this -> year;
    }
};