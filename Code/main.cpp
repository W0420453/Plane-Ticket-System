#include <iostream>
#include "Person.cpp"
#include "Plane.cpp"
using namespace std;


int main() {

    Plane plane;
    bool wantToContinue = true;
    string answer;

    while (wantToContinue)
    {
        plane.AddPassenger();
        cout << "Do you want to continue? (y/n)";
        cin >> answer;

        if (answer == "y" || answer == "Y") 
            wantToContinue = true;
        else if (answer == "n" || answer == "N")
            wantToContinue = false;
    }

    cout << "Thank you for using the program";
    
}