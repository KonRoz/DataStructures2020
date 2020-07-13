/*
author: Konrad Rozanski
file: main.py

This file creates the menu through which the user can access the 
functionality of the VideoGameCollection class.

The user can use each of the seven given options.

The program asks the user to choose another option after one
is selected.

An unspecified option cannot be chosen --> the program will just ask
for a legitamite option.
*/

#include <string>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <climits>
#include "VideoGame.h"
#include "VideoGameCollection.h"

using namespace std;

int main()
{
    //instantiating the container class
    VideoGameCollection myVideoGameCollection;

    string fileName;

    cout << "Welcome to the Video Game Collection Program \n\n";
    char selected;

    cout << "XML or CSV File Name : ";
    cin >> fileName;
    myVideoGameCollection.loadDataAutomatically(fileName);

    while (selected != '7')
    {
        cout << "\n\n\t\tVideo Games Menu\n\n";
        cout << "Items : " << VideoGame::num_games << "\n";

        cout << "1. Display Complete List of Video Games\n";
        cout << "2. Add a new Video Game To End\n";
        cout << "3. Delete a Video Game From End\n";
        cout << "4. Modify Product Field\n";
        cout << "5. Create Updated CSV\n";
        cout << "6. Generate Report (2 Field Filter)\n";
        cout << "7. Exit Program\n";

        cout << "Select Value : "; 
        cin >> selected;

        switch (selected)
        {
            case '1':   myVideoGameCollection.printReport();
                        break;

            case '2':   myVideoGameCollection.addVideoGameToEnd();
                        break;

            case '3':   myVideoGameCollection.deleteVideoGameFromEnd();
                        break;

            case '4':   myVideoGameCollection.modifyProductField();
                        break;

            case '5':   myVideoGameCollection.generateNewCSV(fileName);
                        break;

            case '6':   myVideoGameCollection.printFilteredReport();
                        break;

            case '7':   break;

            default:    cout << "\nPLEASE SELECT A VALID OPTION!\n" << endl;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return 0;
}
