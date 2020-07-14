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

    cout << "Welcome to the Video Game Sorting Program \n\n";
    char selected;

    cout << "XML or CSV File Name : ";
    cin >> fileName;
    myVideoGameCollection.loadDataAutomatically(fileName);

    while (selected != '6')
    {
        cout << "\n\n\t\tVideo Games Menu\n\n";
        cout << "Items : " << VideoGame::num_games << "\n";

        cout << "1. Display Original Order of Video Games\n";
        cout << "2. Price Sort          (Bubble Sort --> Recursive)\n";
        cout << "3. Release Year Sort   (Bubble Sort --> Non-Recursive)\n";
        cout << "4. Title Sort          (Insertion Sort --> Recursive)\n";
        cout << "5. Game Time Sort      (Merge Sort --> Recursive)\n";
        cout << "6. Exit Program\n";

        cout << "Select Value : "; 
        cin >> selected;

        switch (selected)
        {
            case '1':   myVideoGameCollection.printReport();
                        break;

            case '2':   myVideoGameCollection.recursiveBubbleSortDescription(24);
                        myVideoGameCollection.printReport();
                        break;

            case '3':   myVideoGameCollection.nonRecursiveBubbleSort(24);
                        myVideoGameCollection.printReport();
                        break;

            case '4':   myVideoGameCollection.recursiveInsertionSortDescription(24);
                        myVideoGameCollection.printReport();
                        break;

            case '5':   myVideoGameCollection.recursiveMergeSortDescription(0, 23);
                        myVideoGameCollection.printReport();
                        break;

            case '6':   break;

            default:    cout << "\nPLEASE SELECT A VALID OPTION!\n" << endl;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return 0;
}
