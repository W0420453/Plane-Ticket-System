#include <iostream>
using namespace std;

class Person
{
public:
    string firstName = "";
    string lastName = "";
    int day = 0;
    int month = 0;
    int year = 0;

    void GetFullName()
    {
        cout << "Enter your first name: ";
        // needs input validation
        cin >> this->firstName;

        cout << endl
             << "Enter your last name: ";
        // needs input validation
        cin >> this->lastName;
    }

    bool ValidateInput(const string &input)
    {
        int flag = 0;

        // Input validation
        if (input.empty())
        {
            // Handle empty input
            cout << "Input is empty" << endl;
        }
        else
        {
            flag = 0; // Reset the flag for each new input
            for (int i = 0; i < input.size(); i++)
            {
                if (!isdigit(input[i]))
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1)
            {
                cout << "Not numeric" << endl;
            }
            else
            {
                cout << "Yay, Numeric" << endl;
            }
        }

        return flag == 0; // Return true if input is numeric, false otherwise
    }

    void GetBirthday()
    {
        string valMonth;
        string valDay;
        string valYear;
        int flag = 0;
        // 1d array with the days in each month
        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // val for month for number
        do
        {
            cout << endl
                 << "Enter your birthday Month(mm): ";
            cin >> valMonth;

        } while (valMonth.empty() || !ValidateInput(valMonth) || stoi(valMonth) < 1 || stoi(valMonth) > 12);
        do
        {
            //     val for day ofr number
            cout << endl
                 << "Enter your birthday Day(dd): ";
            // needs input validation
            cin >> valDay;
        } while (valDay.empty() || !ValidateInput(valDay) || stoi(valDay) < 1 || stoi(valDay) > daysInMonth[stoi(valMonth) - 1]);
        do
        {
            // val for year as number
            cout << endl
                 << "Enter your birthday Year(yyyy): ";
            // needs input validation
            cin >> valYear;
        } while (valYear.empty() || !ValidateInput(valYear) || stoi(valYear) < 1);
    }
}
;