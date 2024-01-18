#include <iostream>
using namespace std;


class Person {
    public:
    string firstName = "";
    string lastName = "";
    int day = 0;
    int month = 0;
    int year = 0;

    void GetFullName(){
        cout << "Enter your first name: ";
        //needs input validation
        cin >> this -> firstName;


        cout << endl <<  "Enter your last name: ";
        //needs input validation
        cin >> this -> lastName;
    }

    void GetBirthday(){

        cout << endl << "Enter your birthday Month(mm): ";
//       needs input validation
        cin >> this -> month;
//        fflush(stdin);
        cout << endl << "Enter your birthday Day(dd): ";
        //needs input validation
        cin >> this -> day;
        cout << endl << "Enter your birthday Year(yyyy): ";
        //needs input validation
        cin >> this -> year;
    }
};