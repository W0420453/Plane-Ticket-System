#include <iostream>
#include <fstream>
// #include "Person.cpp"
using namespace std;

class Plane {

    private:
        static const int NUMBEROFSEATS = 10;
        //Making the assumption that the number of seats are equal between First Class and Economy
        int FirstClassRange[2] = {0,(NUMBEROFSEATS/2) - 1}; //First half of the plane  (Min, Max)
        int EconomyRange[2] = {(NUMBEROFSEATS/2),(NUMBEROFSEATS - 1)}; //Back half of the plane (Min, Max)
        int FullPlaneRange[2] = {0,(NUMBEROFSEATS - 1)}; // Entire Plane (Min, Max)
        Person Passengers[NUMBEROFSEATS];

    public: 
    Plane() 
    {
        //Do check for wait-list, attempt to add all customers on the waitlist, before adding new passengers
        // Also, remove Passengers from wait-list when they are added
        for (int i = 0; i < NUMBEROFSEATS; i++) 
        {
            Passengers[i] = Person();
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
            if (sectionName == "First Class") {FirstClass();}
            else if (sectionName == "Economy") {Economy();}
            else { cout << "\nAn Error has Occured, please try again later" << endl;}
        }
    }

    bool CheckSeatsAvaliable(int seatsToCheck[2]) 
    {
        for (int i = seatsToCheck[0]; i <= seatsToCheck[1]; i++) 
        {
            // cout <<  "Checking Seat[" << i << "] | Passenger First Name: " << this -> Passengers[i].firstName << endl;
            if (Passengers[i].firstName == "")
            {
                return true;
            }
        }
        //If no seats are available, return false
        return false;
    }

// Function to view all available seats
    void ViewAvailableSeats()
    {
        // Loop through all the seats
        for (int i = 0; i < NUMBEROFSEATS; i++)
        {
            // If the firstName attribute of the Passenger at the current seat is empty,
            // it means the seat is available
            if (Passengers[i].firstName == "")
            {
                // Print a message indicating that the seat is available
                cout << "Seat " << i+1 << " is available." << endl;
            }
            else
            {
                // If the firstName attribute of the Passenger at the current seat is not empty,
                // it means the seat is occupied
                // Print a message indicating that the seat is occupied and by whom
                cout << "Seat " << i+1 << " is occupied by " << Passengers[i].firstName << " " << Passengers[i].lastName << "." << endl;
            }
        }
    }

    string AskForSection()
    {
        string sectionSelection;
        string sectionString = "NotSet";

        while (sectionString == "NotSet")
        {
            cout << "Please type 1 for First Class or 2 for Economy: ";
            //TODO Input Validation
            cin >> sectionSelection;

            if (sectionSelection == "1")
            {
                sectionString = "First Class";
                cout << "You have selected First Class" << endl;
            }
            else if (sectionSelection == "2")
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
        if (!isFull)
        {
            cout << "Would you Like to Switch to Economy? (Y/N)";
            cin >> userInput;

            if ((userInput == "Y") || (userInput == "y") )
            {
                if (CheckSeatsAvaliable(EconomyRange)) { Economy(); }
                else 
                { 
                    cout << "Sorry, Economy is full" << endl; 
                    JoinWaitlistPrompt("First Class");
                }      
            }
            else { JoinWaitlistPrompt("First Class"); }
        }
        else 
        {
            for (int i = FirstClassRange[0]; i <= FirstClassRange[1]; i++) 
            {
                if (Passengers[i].firstName == "")
                {
                    Passengers[i] = Person();
                    Passengers[i].GetFullName();
                    Passengers[i].GetBirthday();
                    DisplayBoardingPass("First Class", i);
                    BoardingPass("First Class",i);
                    break;
                }
            }
        }
    }

    void Economy() 
    {
        bool isFull = CheckSeatsAvaliable(EconomyRange);
        string userInput;
        if (!isFull)
        {
            cout << "Would you Like to Switch to First Class? (Y/N)";
            cin >> userInput;


            if ( (userInput == "Y") || (userInput == "y") )
            {
                if (CheckSeatsAvaliable(FirstClassRange)) { FirstClass(); }
                else 
                { 
                    cout << "Sorry, First Class is full" << endl; 
                    JoinWaitlistPrompt("Economy");
                } 
            }
            else { JoinWaitlistPrompt("Economy"); }
            
        }
        else 
        {
            for (int i = EconomyRange[0]; i <= EconomyRange[1]; i++) 
            {
                if (Passengers[i].firstName == "")
                {
                    Passengers[i] = Person();
                    Passengers[i].GetFullName();
                    Passengers[i].GetBirthday();
                    DisplayBoardingPass("Economy", i);
                    BoardingPass("Economy",i); 
                    break;
                }
            }

        }
    }
	
	void JoinWaitlistPrompt(string sectionName) 
	{
		string userInput = "Filler";

        do
        {
            cout << endl << "Would the user like to be added to the waitlist?: ";
            cin >> userInput;
            if ( (userInput == "Y") || (userInput == "y"))
            {
                WaitList(sectionName);
            }
            else if ((userInput == "N") || (userInput == "n"))
            {
                //TODO NOTHING, valid and leave this function
            }
            else {
                cout << "Invalid selection" << endl;
            }
        } while ( (userInput != "Y") && (userInput != "y") &&  (userInput != "N") && (userInput != "n")  );
	}

    // View waitlist function
    void ViewWaitlist()
    {
        // Open the waitlist.txt file
        ifstream wait_list("waitlist.txt");
        string line;
        if (wait_list.is_open())
        {
            while (getline(wait_list,line))
            {
                cout << line << endl;
            }
            wait_list.close();
        }
        else // If the file cannot be opened, print an error message
        {
            cout << "An Error has occurred when attempting to read from waitlist.txt" << endl;
        }
    }

    void WaitList(string sectionName) 
    {
        Person waitListPerson = Person();
        waitListPerson.GetFullName();
        waitListPerson.GetBirthday();
        ofstream wait_list("waitlist.txt", ios::app);
        if (wait_list.is_open())
        {
            wait_list << endl << waitListPerson.firstName << " " << waitListPerson.lastName << " | " << waitListPerson.month << "/" << waitListPerson.day << "/" << waitListPerson.year << " | " << sectionName;
            wait_list.close();
        }
        else 
        { cout << "An Error has occured when attempting to print to a file" << endl;}
    }

    void DisplayBoardingPass(string sectionName, int seatNumber)
    {
        cout << endl << "--------------------" << endl;
        //Should we print the seatNumber according to the array, or add 1 so the seats go 1-10 for it to make mroe sense to non-programmers.
        cout << Passengers[seatNumber].firstName << " " << Passengers[seatNumber].lastName << " | " << sectionName << " | " << seatNumber + 1 << endl;
        cout << "--------------------" << endl;
    }

    void BoardingPass(string sectionName, int seatNumber)
    {
        ofstream boarding_pass("boardingpass.txt", ios::app);
        if (boarding_pass.is_open())
        {
            boarding_pass << Passengers[seatNumber].firstName << " " << Passengers[seatNumber].lastName << " | " << sectionName << " | " << seatNumber << endl;
            boarding_pass.close();
        }
        else 
        { 
            cout << "An Error has occured when attempting to print to boardingpass.txt" << endl;
        }
    }
};


