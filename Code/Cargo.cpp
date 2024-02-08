//
// Created by johnw on 2024-02-07.
//

#include "Plane.cpp"

// Luggage class to be used in the Cargo class
class Luggage {
    float weight;           // Weight of the luggage
    string description;     // Description of the luggage


    // Constructor for the Luggage class
    // Getters and Setters for the Luggage class
public:
    Luggage() {
        weight = 0.0;        // Default weight
        description = "";    // Default description
    }

    // Constructor
    Luggage(float weight, string description) {
        this->weight = weight;
        this->description = description;
    }

    void SetWeight(float weight) {
        this->weight = weight;
    }

    float GetWeight() {
        return this->weight;
    }

    void SetDescription(string description) {
        this->description = description;
    }

    string GetDescription() {
        return this->description;
    }
};

// Cargo class that inherits from the Plane class
class Cargo : public Plane {
    Luggage *LuggageArray;              // Array of luggage pointing to the Luggage class
    float LuggageMaxWeight = 50.0;      // Max weight of the luggage

public:
    Cargo(int size) : Plane(size) {
        this->LuggageArray = new Luggage[size];

        for (int i = 0; i < size; i++) {
            LuggageArray[i] = Luggage();
        }
    }

    void AskForLuggage(int seatNumber) {
        string userInput;
        string LuggageWeight;
        string LuggageDescription;
        string something;

        do {
            cout << "Would you like Luggage?: ";
            cin >> userInput;

            if ((userInput[0] == 'Y') || (userInput[0] == 'y')) {
                cout << "How much does your luggage weigh?";
                cin >> LuggageWeight;
                if (stof(LuggageWeight) > 0.0 && stof(LuggageWeight) < LuggageMaxWeight) {
                    cout << "Enter description: ";
                    cin >> LuggageDescription;

                    cout << "Description..: " << LuggageDescription << endl;
                    cout << "Weight..: " << LuggageWeight << endl;
                    cout << "Are you ok with this: " << endl;
                    cin >> something;

                    if ((something[0] == 'Y') || (something[0] == 'y')) {
                        LuggageArray[seatNumber].SetWeight(stof(LuggageWeight));
                        LuggageArray[seatNumber].SetDescription(LuggageDescription);
                    }
                } else {
                    cout << "Invaild weight";
                }
                LuggageArray[seatNumber];
            } else if ((userInput[0] == 'N') || (userInput[0] == 'n')) {
                // Nothing
            } else {
                cout << "Invalid" << endl;
            }
        } while ((userInput[0] != 'Y') && (userInput[0] != 'y') && (userInput[0] != 'N') && (userInput[0] != 'n'));
    }



    /*
     * Economy class function and FirstClass function had to override it in this cargo class because it wouldnt work
     * so we had to override it and add virtual in front of the functions in the Plane class
     *
     */

    void Economy() override
    {
        bool isFull = CheckSeatsAvailable(EconomyRange);
        string userInput;
        if (!isFull) //If isFull is True, then run this section below
        {
            cout << "Would you Like to Switch to First Class? (Y/N)";
            cin >> userInput;


            if ((userInput[0] == 'Y') || (userInput[0] == 'y')) {
                if (CheckSeatsAvailable(FirstClassRange)) { FirstClass(); }
                else {
                    cout << "Sorry, First Class is full" << endl;
                    JoinWaitlistPrompt("Economy");
                }
            } else { JoinWaitlistPrompt("Economy"); }

        } else  //isFull is False, so check which seat is available
        {
            int seatNumber = DetermineSeatAvailable(EconomyRange);
            if (seatNumber != -1) {
                Passengers[seatNumber] = Passenger();
                Passengers[seatNumber].AskFullName();
                Passengers[seatNumber].AskBirthday();
                Passengers[seatNumber].SetSeatNumber(seatNumber);
                Passengers[seatNumber].SetSectionName("Economy");
                AskForLuggage(seatNumber);

                DisplayBoardingPass("Economy", seatNumber);
                BoardingPass("Economy", seatNumber);
            }
        }
    }

    void FirstClass() override
    {
        bool isFull = CheckSeatsAvailable(FirstClassRange);
        string userInput;
        if (!isFull) //If isFull is True, then run this section below
        {
            cout << "Would you Like to Switch to Economy? (Y/N)";
            cin >> userInput;

            if ((userInput[0] == 'Y') || (userInput[0] == 'y') )
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
                Passengers[seatNumber] = Passenger();
                Passengers[seatNumber].AskFullName();
                Passengers[seatNumber].AskBirthday();
                Passengers[seatNumber].SetSeatNumber(seatNumber);
                Passengers[seatNumber].SetSectionName("First Class");
                AskForLuggage(seatNumber);

                DisplayBoardingPass("First Class", seatNumber);
                BoardingPass("First Class",seatNumber);
            }
        }
    }
};