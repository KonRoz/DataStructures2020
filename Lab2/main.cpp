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

    bool select1 = false;
    bool select2 = false;
    bool select3 = false;
    bool select4 = false;

    while (selected != '5')
    {

        cout << "\n\n\t\tVideo Games Menu\n\n";
        cout << "Items : " << VideoGame::num_games << "\n";

        cout << "1. Enter data into the array manually\n";
        cout << "2. Load data from a CSV of XML file into the array\n";
        cout << "3. Print report of elements in the array\n";
        cout << "4. Generate a vector from the array and display the contents\n";
        cout << "5. Exit program\n";

        cout << "\nSelected Values (1 --> Selected) : \n";
        cout << "\t\t\t\tOption 1 : " << select1 << "\n";
        cout << "\t\t\t\tOption 2 : " << select2 << "\n";
        cout << "\t\t\t\tOption 3 : " << select3 << "\n";
        cout << "\t\t\t\tOption 4 : " << select4 << "\n";

        cout << "Select Value : "; 

        selected = getchar();

        if (VideoGame::num_games > 9)
        {
            cout << "The array is full --> Here are the contents : " << endl;
            myVideoGameCollection.printReport();
            break;
        }

        switch (selected)
        {
            case '1':   if (!select1)
                        {
                            myVideoGameCollection.enterDataManually();
                            select1 = true;
                        } else
                        {
                            cout << "You have already entered data manually\n";
                            cout << "Choose another option!\n";
                        }
                        break;

            case '2':   if (!select2)
                        {
                            cout << "XML or CSV File Name : ";
                            cin >> fileName;
                            myVideoGameCollection.loadDataAutomatically(fileName);
                            select2 = true;
                        } else
                        {
                            cout << "You have already loaded data from a file\n";
                            cout << "Choose another option!\n";
                        }
                        break;

            case '3':   if (!select3)
                        {
                            myVideoGameCollection.printReport();
                            select3 = true;
                        } else
                        {
                            cout << "You have already displayed the data\n";
                            cout << "Choose another option!\n";
                        }
                        break;

            case '4':   if (!select4)
                        {
                            myVideoGameCollection.generateAndPrintVector();
                            select4 = true;
                        } else
                        {
                            cout << "You have already generated and printed and vector\n";
                            cout << "Choose another option!\n";
                        }
                        break;

            case '5':   break;

            default:    cout << "\nPLEASE SELECT A VALID OPTION!\n" << endl;
        }

        // ensures that all options have been exercised before breaking the loop
        if (select1 && select2 && select3 && select4)
            break;

        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return 0;
}
