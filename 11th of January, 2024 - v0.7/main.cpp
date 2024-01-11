#include <iostream>
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
        if (answer == "y")
            wantToContinue = true;
        else if (answer == "n")
            wantToContinue = false;
    }

    cout << "Thank you for using the program";
}