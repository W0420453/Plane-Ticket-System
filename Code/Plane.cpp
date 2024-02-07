#include <iostream>
#include <fstream>
// #include "Person.cpp"
using namespace std;

class Plane {

    public:
    //Making the assumption that the number of seats are equal between First Class and Economy
    int FirstClassRange[2]; //First half of the plane  (Min, Max)
    int EconomyRange[2]; //Back half of the plane (Min, Max)
    int FullPlaneRange[2]; // Entire Plane (Min, Max)
    int numberOfSeats;

    // Pointer of Person sized Named Passenger | To be replaced when the array size is determined
    Person* Passengers;

    Plane(int size) : numberOfSeats(10)
    {
        this -> numberOfSeats = size;
        // Overwrite the Person Pointer named Passenger with an array of Person's
        Passengers = new Person[numberOfSeats];
        for (int i = 0; i < numberOfSeats; i++)
        {
            Passengers[i] = Person();
        }

        //First half of the plane  (Min, Max)
        this -> FirstClassRange[0] = 0;
        this -> FirstClassRange[1] = ((numberOfSeats/2) - 1);

        //Back half of the plane (Min, Max)
        this -> EconomyRange[0] = (numberOfSeats/2);
        this -> EconomyRange[1] = (numberOfSeats - 1);

        // Entire Plane (Min, Max)
        this -> FullPlaneRange[0] = 0;
        this -> FullPlaneRange[1] = (numberOfSeats - 1);
    }

    //Add a Passenger to the Plane, use this function to add passengers directly to the plane via prompts
    void AddPassenger()
    {
        string sectionName = AskForSection();
        if (!CheckSeatsAvailable(FullPlaneRange))
        {
            cout << "Sorry, the Plane is Full" << endl;
            JoinWaitlistPrompt(sectionName);
        }
        else 
        {
            if (sectionName == "First Class") {FirstClass();}
            else if (sectionName == "Economy") {Economy();}
            else { cout << "\nAn Error has Occurred, please try again later" << endl;}
        }
    }

    //Checks all seats in the given range, returning true if it finds an empty seat, otherwise (else) return false
    bool CheckSeatsAvailable(const int seatsToCheck[2])
    {
        for (int i = seatsToCheck[0]; i <= seatsToCheck[1]; i++) 
        {
            if (Passengers[i].firstName.empty())
            {
                return true;
            }
        }
        //If no seats are available, return false
        return false;
    }

    //Similar to CheckSeatsAvailable, but returns the Seat number instead of true or false
    int DetermineSeatAvailable(const int seatsToCheck[2])
    {
        for (int i = seatsToCheck[0]; i <= seatsToCheck[1]; i++)
        {
            if (Passengers[i].firstName.empty())
            {
                return i; //Returning the equivalent seat number POS in the passengers
            }
        }
        //If no seats are available, return -1
        return -1;
    }

// Function to view all available seats
    void ViewAvailableSeats()
    {
        // Loop through all the seats | NOT using the functions due to needing to loop through all seats every time.
        for (int i = 0; i <= FullPlaneRange[1]; i++)
        {
            // If the firstName attribute of the Passenger at the current seat is empty,
            // it means the seat is available
            if (Passengers[i].firstName.empty())
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

    //Prompt the user for the Section of the plane they wish to Purchase a Seat from
    string AskForSection()
    {
        string sectionSelection;
        string sectionString = "NotSet";

        while (sectionString == "NotSet")
        {
            cout << "Please type 1 for First Class or 2 for Economy: ";
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
        bool isFull = CheckSeatsAvailable(FirstClassRange);
        string userInput;
        if (!isFull) //If isFull is True, then run this section below
        {
            cout << "Would you Like to Switch to Economy? (Y/N)";
            cin >> userInput;

            if ((userInput == "Y") || (userInput == "y") )
            {
                if (CheckSeatsAvailable(EconomyRange)) { Economy(); }
                else 
                { 
                    cout << "Sorry, Economy is full" << endl; 
                    JoinWaitlistPrompt("First Class");
                }      
            }
            else { JoinWaitlistPrompt("First Class"); }
        }
        else //isFull is False, so check which seat is available
        {
            int seatNumber = DetermineSeatAvailable(FirstClassRange);
            if (seatNumber != -1)
            {
                    Passengers[seatNumber] = Person();
                    Passengers[seatNumber].GetFullName();
                    Passengers[seatNumber].GetBirthday();
                    DisplayBoardingPass("First Class", seatNumber);
                    BoardingPass("First Class",seatNumber);
            }
            // Old method before int DetermineSeatAvailable(RangeOfSeats) was created
//            for (int i = FirstClassRange[0]; i <= FirstClassRange[1]; i++)
//            {
//                if (Passengers[i].firstName.empty())
//                {
//                    Passengers[i] = Person();
//                    Passengers[i].GetFullName();
//                    Passengers[i].GetBirthday();
//                    DisplayBoardingPass("First Class", i);
//                    BoardingPass("First Class",i);
//                    break;
//                }
//            }
        }
    }

    void Economy() 
    {
        bool isFull = CheckSeatsAvailable(EconomyRange);
        string userInput;
        if (!isFull) //If isFull is True, then run this section below
        {
            cout << "Would you Like to Switch to First Class? (Y/N)";
            cin >> userInput;


            if ( (userInput == "Y") || (userInput == "y") )
            {
                if (CheckSeatsAvailable(FirstClassRange)) { FirstClass(); }
                else 
                { 
                    cout << "Sorry, First Class is full" << endl; 
                    JoinWaitlistPrompt("Economy");
                } 
            }
            else { JoinWaitlistPrompt("Economy"); }
            
        }
        else  //isFull is False, so check which seat is available
        {
            int seatNumber = DetermineSeatAvailable(EconomyRange);
            if (seatNumber != -1)
            {
                Passengers[seatNumber] = Person();
                Passengers[seatNumber].GetFullName();
                Passengers[seatNumber].GetBirthday();
                DisplayBoardingPass("Economy", seatNumber);
                BoardingPass("Economy", seatNumber);
            }
        }

//            //Find seat to assign - TURN INTO SEPARATE FUNCTION
//            for (int i = EconomyRange[0]; i <= EconomyRange[1]; i++)
//            {
//                if (Passengers[i].firstName.empty())
//                {
//                    Passengers[i] = Person();
//                    Passengers[i].GetFullName();
//                    Passengers[i].GetBirthday();
//                    DisplayBoardingPass("Economy", i);
//                    BoardingPass("Economy",i);
//                    break;
//                }
//            }
    }
	
	void JoinWaitlistPrompt(const string& sectionName)
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
            // This always equals True, until one of the 4 userInput checks returns False.  Due using &&'s the checks will all fail and then the while loop will end.
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
            cout << "There is currently no Wait list or it is empty" << endl;
        }
    }

    void WaitList(const string& sectionName)
    {
        Person waitListPerson = Person();
        waitListPerson.GetFullName();
        waitListPerson.GetBirthday();
        ofstream wait_list("waitlist.txt", ios::app);
        if (wait_list.is_open())
        {
            wait_list << waitListPerson.firstName << " " << waitListPerson.lastName << " | " << waitListPerson.month << "/" << waitListPerson.day << "/" << waitListPerson.year << " | " << sectionName << endl;
            wait_list.close();
        }
        else 
        { cout << "An Error has occurred when attempting to print to a file" << endl;}
    }

    string SpliceString(string& line, char delimiter)
    {
        //Position of Delimiter | NOTE: need to add + 1 when using substr to remove the delimiter itself.
        size_t delimiterPOS = line.find(delimiter);
        string stringObtained;

        // delimiterPOS is equal to std::string::npos when std::string::find fails to find the delimiter it is looking for.
        if (delimiterPOS != std::string::npos)
        {
            stringObtained = line.substr(0,delimiterPOS);;

            // Removing the extra space at the start of each section of the line
            if (delimiter == '|') { line = line.substr(delimiterPOS + 2); }
            //Removing everything before and including the delimiter from the string
            else {line = line.substr(delimiterPOS + 1); }
        }
        else { stringObtained = line;}

        return stringObtained;
    }


    /*
     * Function to fill up the boardingPass
     */
    void BackFillBoardingPass()
    {
        ifstream wait_list;
        wait_list.open("waitlist.txt");
        ofstream temp_wait_list;
        temp_wait_list.open("temp_waitlist.txt");
        // Full String retrieved from the file, never to be modified. | Kept for deleting the line when it finds the match for it.
        string currentLine;
        // Copy of currentLine, but has already used data removed from the start of it to make future searches shorter
        string modifiedLine;
        int seatNumber;

        bool isFirstClassFull = false;
        bool isEconomyFull = false;

        if (wait_list.is_open())
        {
            // While there is a line to search through, and both First Class AND Economy are not full
            // not using !wait_list.eof() because it is a bug, which will read an empty new line as a valid time to continue
            // https://stackoverflow.com/questions/5605125/why-is-iostreameof-inside-a-loop-condition-i-e-while-stream-eof-cons
            while (getline(wait_list, currentLine) && !(isFirstClassFull && isEconomyFull) )
            {
                modifiedLine = currentLine;

                // Checking if the current line contains First Class, and if First Class is full, using a bool instead of checking to avoid unnecessary searching through seats when it is full.
                if (currentLine.find("First Class") && !isFirstClassFull)
                {
                    seatNumber = DetermineSeatAvailable(FirstClassRange);
                    if (seatNumber != -1)
                    {
                        AddWaitlistPassenger(seatNumber, modifiedLine);
                        if ( seatNumber == FirstClassRange[1])  { isFirstClassFull = true; }
                    }

                    //Old Method
//                    for (int i = FirstClassRange[0]; i <= FirstClassRange[1]; i++)
//                    {
//                        if (Passengers[i].firstName == "")
//                        {
//
//                            AddWaitlistPassenger(i, modifiedLine);
//                            // Check if the seat assigned is the same as the last seat fot the section
//                            if ( (i == FirstClassRange[1]))  { isFirstClassFull = true; }
//                            break;
//                        }
//                    }
                }
                else if (currentLine.find("Economy") && !isEconomyFull)
                {
                    seatNumber = DetermineSeatAvailable(EconomyRange);
                    if (seatNumber != -1)
                    {
                        AddWaitlistPassenger(seatNumber, modifiedLine);
                        if ( seatNumber == EconomyRange[1])  { isEconomyFull = true; }
                    }
//                    //Old Method
//                    for (int i = EconomyRange[0]; i <= EconomyRange[1]; i++)
//                    {
//                        if (Passengers[i].firstName.empty())
//                        {
//                            AddWaitlistPassenger(i, modifiedLine);
//                            // Check if the seat assigned is the same as the last seat fot the section
//                            if ( i == EconomyRange[1])  { isEconomyFull = true; }
//                            break;
//                        }
//                    }
                }
                // If the plane is full, or the section cannot be found, add them to the temp wait list
                else 
                {
                    temp_wait_list << currentLine << endl;
                }
            }
            wait_list.close();
            temp_wait_list.close();
            
            //Swapping the temp waitlist with the real waitlist
            remove("waitlist.txt");
            rename("temp_waitlist.txt", "waitlist.txt");
        }
    }

    void AddWaitlistPassenger(const int& i, string& modifiedLine)
    {
        int day;
        int month;
        int year;

        //Section Name is used multiple times.
        string sectionName;
        // Completely Useless string, just used to store the return value from SpliceString when removing '|'.
        string useless;

        Passengers[i] = Person();
        Passengers[i].SetFirstName(SpliceString(modifiedLine, ' '));
        Passengers[i].SetLastName(SpliceString(modifiedLine, ' '));

        //Value is never used
        useless = SpliceString(modifiedLine, '|');

        // stoi has a hissy fit if it's done inside SetBirthDate, so the extra variables are required
        day = stoi(SpliceString(modifiedLine, '/'));
        month =  stoi(SpliceString(modifiedLine, '/'));
        year = stoi(SpliceString(modifiedLine, ' '));

        Passengers[i].SetBirthDate(month,day,year);

        //Value is never used
        useless = SpliceString(modifiedLine, '|');

        sectionName = SpliceString(modifiedLine, '|');

        DisplayBoardingPass(sectionName, i);
        BoardingPass(sectionName,i);
    }

    void DisplayBoardingPass(const string& sectionName, int seatNumber)
    {
        cout << endl << "--------------------" << endl;
        //Should we print the seatNumber according to the array, or add 1 so the seats go 1-10 for it to make more sense to non-programmers.
        cout << Passengers[seatNumber].firstName << " " << Passengers[seatNumber].lastName << " | " << sectionName << " | " << seatNumber + 1 << endl;
        cout << "--------------------" << endl;
    }

    void BoardingPass(const string& sectionName, int seatNumber)
    {
        ofstream boarding_pass("boardingpass.txt", ios::app);
        if (boarding_pass.is_open())
        {
            boarding_pass << Passengers[seatNumber].firstName << " " << Passengers[seatNumber].lastName << " | " << sectionName << " | " << seatNumber << endl;
            boarding_pass.close();
        }
        else 
        { 
            cout << "An Error has occurred when attempting to print to boardingpass.txt" << endl;
        }
    }
};
