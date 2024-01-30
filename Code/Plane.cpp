#include <iostream>
#include <fstream>
// #include "Person.cpp"
using namespace std;

class Plane {

    public:
//    static const int NUMBEROFSEATS = 10;
//    //Making the assumption that the number of seats are equal between First Class and Economy
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
	
    void AddPassenger()
    {
        string sectionName = AskForSection();
        if (!CheckSeatsAvaliable(FullPlaneRange))
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

    bool CheckSeatsAvaliable(int seatsToCheck[2]) 
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

// Function to view all available seats
    void ViewAvailableSeats()
    {
        // Loop through all the seats
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
                if (Passengers[i].firstName.empty())
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
            //Find seat to assign - TURN INTO SEPERATE FUNCTION
            for (int i = EconomyRange[0]; i <= EconomyRange[1]; i++) 
            {
                if (Passengers[i].firstName.empty())
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
            wait_list << waitListPerson.firstName << " " << waitListPerson.lastName << " | " << waitListPerson.month << "/" << waitListPerson.day << "/" << waitListPerson.year << " | " << sectionName << endl;
            wait_list.close();
        }
        else 
        { cout << "An Error has occurred when attempting to print to a file" << endl;}
    }

    string SpliceString(string& line, char delimiter)
    {
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
        string modifedLine;
        //Position of Delimiter | NOTE: need to add + 1 when using substr to remove the delimiter itself. | +3 to remove ending space, delimiter, and starting space for each section
        size_t delimiterPOS;

        bool isFirstClassFull = false;
        bool isEconomyFull = false;

        if (wait_list.is_open())
        {
            // While there is a line to search through, and both First Class AND Economy are not full
            // not using !wait_list.eof() because it is a bug, which will read an empty new line as a valid time to continue
            // https://stackoverflow.com/questions/5605125/why-is-iostreameof-inside-a-loop-condition-i-e-while-stream-eof-cons
            while (getline(wait_list, currentLine) && !(isFirstClassFull && isEconomyFull) )
            {
                modifedLine = currentLine; 

                // Checking if the current line contains First Class, and if First Class is full, using a bool instead of checking to avoid unnecessary searching through seats when it is full.
                if (currentLine.find("First Class") && !isFirstClassFull)
                {
                    for (int i = FirstClassRange[0]; i <= FirstClassRange[1]; i++) 
                    {
                        if (Passengers[i].firstName == "")
                        {

                            AddWaitlistPassenger(i, modifedLine);
                            // Check if the seat assigned is the same as the last seat fot the section
                            if ( (i = FirstClassRange[1]))  { isFirstClassFull = true; }
                            break;
                        }
                    }
                }
                else if (currentLine.find("Economy") && !isEconomyFull)
                {
                    //Find seat to assign - TURN INTO SEPERATE FUNCTION
                    for (int i = EconomyRange[0]; i <= EconomyRange[1]; i++) 
                    {
                        if (Passengers[i].firstName == "")
                        {
                            AddWaitlistPassenger(i, modifedLine);
                            // Check if the seat assigned is the same as the last seat fot the section
                            if ( (i = EconomyRange[1]))  { isEconomyFull = true; }
                            break;
                        }
                    }
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

    void AddWaitlistPassenger(int i, string& modifedLine)
    {
        Passengers[i] = Person();
        Passengers[i].SetFirstName(SpliceString(modifedLine, ' '));
        Passengers[i].SetLastName(SpliceString(modifedLine, ' '));

        //returning nothing to this string, so the function SpliceString can be called to remove the | delimiter but not use the value obtained
        string useless = SpliceString(modifedLine, '|');

        int day = stoi(SpliceString(modifedLine, '/'));
        int month =  stoi(SpliceString(modifedLine, '/'));
        int year = stoi(SpliceString(modifedLine, ' '));

        Passengers[i].SetBirthDate(month,day,year);

        //returning nothing to this string, so the function SpliceString can be called to remove the | delimiter but not use the value obtained
        useless = SpliceString(modifedLine, '|');

        //Since Section Name is used multiple times, and to future-proof this code.  This variable is required
        string secitonName = SpliceString(modifedLine, '|');

        DisplayBoardingPass(secitonName, i);
        BoardingPass(secitonName,i);
    }

    void DisplayBoardingPass(string sectionName, int seatNumber)
    {
        cout << endl << "--------------------" << endl;
        //Should we print the seatNumber according to the array, or add 1 so the seats go 1-10 for it to make more sense to non-programmers.
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
            cout << "An Error has occurred when attempting to print to boardingpass.txt" << endl;
        }
    }
};


