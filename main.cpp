#include "theEngineer.h"
#include "theEngineerList.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <limits>
#include <cctype>

using namespace std;

const int MAX_VAL = 100;

int main()
{

    engineer anEngineer;
    theEngineerList engineerList;

    char *lastName = new char[MAX_VAL];
    char *firstName = new char[MAX_VAL];
    titleLevel engineerTitle;
    int assessmentLevel, engineerCount, index;

    const char *fileName = "theEngineer.txt";

    engineerList.loadEngineer(fileName);

    char choice[3];

    char option[3];

    cout << "Fill in the empty fields mentioned below, when you have entered all the fields, select Q)uit" << endl;

    do
    {

        cout << "What would you like to do? "
             << "(L)ist, (A)dd, (P)romote, (E)dit, (R)emove, " << endl;

        cin.getline(option, 3);
        char ch = toupper(option[0]);

        if (option[0] == '\0')
        {
            continue;
        }

        switch (ch)
        {

        case 'L':
            engineerList.printEngineer();
            break;

        case 'A':
        {
            cout << "You have chosen to add an Engineer" << endl;
            cout << "Enter engineer last name: ";
            cin.getline(lastName, MAX_VAL);

            if (lastName[0] == '\0')
            {
                break;
            }

            cout << "Enter engineer first name: ";
            cin.getline(firstName, MAX_VAL);

            if (firstName[0] == '\0')
            {
                continue;
            }

            cout << "Pick engineer title level by selecting(a-h): " << endl
                 << endl;

            cout << "a): L1" << endl;
            cout << "b): L2" << endl;
            cout << "c): L3" << endl;
            cout << "d): L4" << endl;
            cout << "e): L5" << endl;
            cout << "f): L6" << endl;
            cout << "g): L7" << endl;
            cout << "h): L8" << endl;

            cin.getline(choice, 3);

            if (option[0] == '\0')
            {
                continue;
            }

            switch (choice[0])
            {

            case 'a':
                engineerTitle = L1;
                break;
            case 'b':
                engineerTitle = L2;
                break;
            case 'c':
                engineerTitle = L3;
                break;
            case 'd':
                engineerTitle = L4;
                break;
            case 'e':
                engineerTitle = L5;
                break;
            case 'f':
                engineerTitle = L6;
                break;
            case 'g':
                engineerTitle = L7;
                break;
            case 'h':
                engineerTitle = L8;
                break;
            default:
                cout << "Invalid choice, defaulting to L1.\n";
                engineerTitle = L1;
            }

            cout << "Enter an assesment level, 1 - 5 : " << endl;
            cin >> assessmentLevel;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            engineerCount = anEngineer.getCount();

            anEngineer.setEngineer(lastName, firstName, engineerTitle, assessmentLevel, engineerCount);
            engineerList.insert(anEngineer);
            break;
        }

        case 'P':
        {

            cout << "You selected promote" << endl;
            engineerList.promote(anEngineer);
            break;
        }

        case 'E':
        {

            cout << "You selected edit assessment level" << endl;
            cout << "Please enter the index of the Engineer who's assessment level you want to edit: ";
            cin >> index;
            cout << endl
                 << "What would you like to change the assessment to?: ";
            cin >> assessmentLevel;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            engineerList.editAssessment(index, assessmentLevel);
            break;
        }

        case 'Q':
        {
            cout << "Program exit. " << endl;
            break;
        }
        default:
        {
            cout << ch << " not an option" << endl;
            break;
        }

        case 'R':
        {
            cout << "You selected remove all engineers with a performance rating of 1" << endl;
            engineerList.remove();
        }
        }

    } while (toupper(option[0]) != 'Q');

    anEngineer.setEngineer(lastName, firstName, engineerTitle, assessmentLevel, engineerCount);

    // insert the created engineer so it appears in the list
    engineerList.insert(anEngineer);

    engineerList.printEngineer();

    return 0;
}
