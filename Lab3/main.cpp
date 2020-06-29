/*
author: Konrad Rozanski
file: main.py

This file creates the menu through which the user can access the 
functionality of the VideoGameCollection class.

The user can use each of the five given options before the program
automatically exits.

Likewise, the same option cannot be used twice. The program asks the 
user to choose another option if that is the case.

An unspecified option cannot be chosen --> the program will just ask
for a legitamite option.

There is a window displaying whether each option has been chosen at least
once. A 1 indicates that the option has been chosen before. A 0 indicates
the option has not yet been exercised.
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
    char selected = '0';

    cout << "XML or CSV File Name : ";
    cin >> fileName;
    myVideoGameCollection.loadDataAutomatically(fileName);

    while (selected != '5')
    {

        cout << "\n\n\t\tVideo Games Menu\n\n";
        cout << "Items : " << VideoGame::num_games << "\n";

        cout << "1. Display Complete List of Video GAmes\n";
        cout << "2. Add a new Video Game\n";
        cout << "3. Delete a Video Game\n";
        cout << "4. Exit Program\n";

        cout << "Select Value : "; 

        selected = getchar();

        switch (selected)
        {
            case '1':   myVideoGameCollection.printReport();
                        break;

            case '2':   // Add a Video Game
                        break;

            case '3':   // Delete a Video Game
                        break;

            case '4':   break;

            default:    cout << "\nPLEASE SELECT A VALID OPTION!\n" << endl;
        }

        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return 0;
}
