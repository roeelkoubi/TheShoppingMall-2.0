#include "GeneralFunctions.h"

int getIntFromUser(const char* msg, size_t min, size_t max)
{
    int retVal = -1;
    bool valid = false;
    while (!valid) {
        cout << "--> Please enter " << msg << " (between " << min << " and " << max << "):" << "\n";

        cin >> retVal;
        if (retVal < min || retVal > max)
            cout << "Invalid number entered" << endl;
        else
            valid = true;
    }
    return retVal;
}

double getDoubleFromUser(const char* msg, double min, double max)
{
    double retVal = -1;
    bool valid = false;
    while (!valid) {
        cout << "Please enter " << msg << " (between " << min << " and " << max << "):" << "\n";

        cin >> retVal;
        if (retVal < min || retVal > max)
            cout << "Invalid number entered";
        else
            valid = true;
    }
    return retVal;
}

void cleanBuffer()
{
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
}

void showMenu()
{
    cout << "Please select one of the options below:" << endl;
    cout << "1. Create Store" << endl;
    cout << "2. Create Employee" << endl;
    cout << "3. Create Client" << endl;
    cout << "4. Show Mall Employees" << endl;
    cout << "5. Show Mall Stores" << endl;
    cout << "6. Show Mall" << endl;
    cout << "7. Select Store" << endl;
    cout << "8. Exit Program" << endl;
    cout << "--------------------------------" << endl;
}

