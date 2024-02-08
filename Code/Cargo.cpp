//
// Created by johnw on 2024-02-07.
//

#include "Plane.cpp"

class Luggage {
    float weight;
    string description;

public:
    Luggage() {
        weight = 0.0;
        description = "";
    }

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


class Cargo : public Plane {
    Luggage* LuggageArray;
    float LuggageMaxWeight = 50.0;

public:
    Cargo(int size) : Plane(size) {
        this -> LuggageArray = new Luggage[size];

        for (int i = 0; i < size; i++)
        {
            LuggageArray[i] = Luggage();
        }
    }

    void AskForLuggage(int seatNumber) {
        string userInput;
        float LuggageWeight;
        string LuggageDescription;
        string something;

        do {
            cout << "Would you like Laggage?: ";
            cin >> userInput;

            if ((userInput[0] == 'Y') || (userInput[0] == 'y'))
            {
                cout << "How much does your laggage weigh?";
                cin >> LuggageWeight;
                if (isdigit(LuggageWeight) && LuggageWeight > 0.0 && LuggageWeight < LuggageMaxWeight)
                {
                    cout << "Enter description: ";
                    cin >> LuggageDescription;

                    cout << "Description..: " << LuggageDescription << endl;
                    cout << "Weight..: " << LuggageWeight << endl;
                    cout << "Are you ok with this: " << endl;
                    cin >> something;

                    if ((something[0] == 'Y') || (something[0] == 'y')){
                        LuggageArray[seatNumber].SetWeight(LuggageWeight);
                        LuggageArray[seatNumber].SetDescription(LuggageDescription);
                    }
                }

                else
                {
                    cout << "Invaild weight";
                }
                LuggageArray[seatNumber];
            }
            else if ((userInput[0] == 'N') || (userInput[0] == 'n'))
            {
                // Nothing
            }
            else
            {
                cout << "Invalid" << endl;
            }
        } while ( (userInput[0] != 'Y') && (userInput[0] != 'y') &&  (userInput[0] != 'N') && (userInput[0] != 'n')  );
    };