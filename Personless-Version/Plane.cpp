#include <iostream>
#include <fstream>
#include "Person.cpp"
using namespace std;

class Plane {

    private:
        static const int numberOfSeats = 10;
        int FirstClassRange[2] = {0,4};
        int EconomyRange[2] = {5,9};
        int FullPlaneRange[2] = {0,9};
        Person Passengers[numberOfSeats];

    public: 
    Plane() 
    {
        // for (int i = 0; i < numberOfSeats; i++) 
        // {
        //     Passengers[i] = Person("","",0,0,0);
        // }
    }
	
	void JoinWaitlistPrompt(string sectionName) 
	{
		string userInput;
		cout << "\nWould the user like to be added to the waitlist?"  << endl;
        cin >> userInput;
		if ( (userInput == "Y") || (userInput == "y"))
        {
            waitList(sectionName);
        }
	}
	
    void AddPassenger()
    {
        string sectionName = AskForSection();
        if (CheckSeatsAvaliable(FullPlaneRange) != true)
        {
            cout << "Sorry, the Plane is Full" << endl;
            JoinWaitlistPrompt(sectionName);
        }
        else 
        {
            if(sectionName == "FirstClass") {FirstClass();}
            else if (sectionName == "Economy") {Economy();}
            else { cout << "\nAn Error has Occured, please try again later" << endl;}
        }
    }

    bool CheckSeatsAvaliable(int seatsToCheck[2]) 
    {
        for (int i = seatsToCheck[0]; i <= seatsToCheck[1]; i++) 
        {
            if (Passengers[i].firstName == "")
            {
                return true;
            }
        }
        //If no seats are avaliable, return false
        return false;
    }

    string AskForSection()
    {
        int sectionSelection;
        string sectionString = "NotSet";

        while (sectionString == "NotSet")
        {
            cout << "Please type 1 for First Class or 2 for Economy: ";
            cin >> sectionSelection;

            if (sectionSelection = 1)
            {
                sectionString = "First Class";
                cout << "You have selected First Class" << endl;
            }
            else if (sectionSelection = 2)
            {
                sectionString = "Economy";
                cout << "You have selected Economy" << endl;
            }
            else
            {
                cout << "Invalid selection" << endl;
            }
        }
        return sectionString;
    }

    void FirstClass() 
    {
        bool isFull = CheckSeatsAvaliable(FirstClassRange);
        string userInput;
        if (isFull)
        {
            cout << "Would you Like to Switch to Economy? (Y/N)";
            cin >> userInput;

            if ( (userInput == "Y") || (userInput == "y") )
            {
                if (CheckSeatsAvaliable(EconomyRange))
                {
                    Economy();
                }
                else
                {
                    cout << "Sorry, First Class is full | Would you like to be added to the waitlist?";
                }
            }
        }
        else 
        {
            for (int i = FirstClassRange[0]; i <= FirstClassRange[1]; i++) 
            {
                if (Passengers[i].firstName == "")
                {
                    Passengers[i] = Person();
                    //print to file, change in a minute
                    break;
                }
            }
        }
    }

    void Economy() 
    {
        bool isFull = CheckSeatsAvaliable(EconomyRange);
        string userInput;
        if (isFull)
        {
            cout << "Would you Like to Switch to First Class? (Y/N)";
            cin >> userInput;

            if ( (userInput == "Y") || (userInput == "y") )
            {
                if (CheckSeatsAvaliable(FirstClassRange))
                {
                    FirstClass();
                }
                else
                {
                    cout << "Sorry, Economy is full | Would you like to be added to the waitlist?";
                }
            }
        }
        else 
        {
            for (int i = EconomyRange[0]; i <= EconomyRange[1]; i++) 
            {
                if (Passengers[i].firstName == "")
                {
                    Passengers[i] = Person();
                    //print to file, change in a minute
                    break;
                }
            }

        }
    }

    void waitList(string sectionName) 
    {
        Person waitListPerson = Person();
        ofstream wait_list("waitlist.txt", ios::app);
        if (wait_list.is_open())
        {
            wait_list << waitListPerson.firstName << " " << waitListPerson.lastName << " | " << waitListPerson.month << "/" << waitListPerson.day << "/" << waitListPerson.year << " | " << sectionName;
            wait_list.close();
        }
        else 
        { cout << "An Error has occured when attempting to print to a file" << endl;}
    }

};