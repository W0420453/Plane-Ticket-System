#include <iostream>
#include "Person.cpp"
#include "Plane.cpp"
using namespace std;


int main() {

    Plane plane(10);

    bool wantToContinue = true;
    string menuSelection;

    remove("boardingpass.txt");

    plane.BackFillBoardingPass();

    while (wantToContinue)
    {
        cout << endl << "Airplane Reservation System!!" << endl;
        cout << "1. Add Passenger" << endl;
        cout << "2. View Wait list" << endl;
        cout << "3. View Available seats" << endl;
        cout << "4. Exit" << endl;
        cin >> menuSelection;
        switch (stoi(menuSelection))
        {
            case 1:
                plane.AddPassenger();
                break;
            case 2:
                plane.ViewWaitlist();
                break;
            case 3:
                plane.ViewAvailableSeats();
                break;
            case 4:
                wantToContinue = false;
                break;
            default:
                cout << "Invalid Selection, please try again" << endl;
                break;
        }
    }
    cout << "Thank you for using the program";
}