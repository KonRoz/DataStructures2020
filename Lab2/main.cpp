/*
author: Konrad Rozanski
file: main.py

Testing VideoGame and Menu class by instantiating 6 objects using the various
constructors and calling the additional methods
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

    // instantiating various video games
    VideoGame callOfDutyBlackOps2('x', 30, "Call of Duty: Black Ops 2", 2012, "Treyarch", "First-person Shooter", true);
    VideoGame zelda ('x', 10, "The Legend of Zelda", 1986, "Nintendo", "Action-adventure", false);
    VideoGame battlefield4 ('p', 40, "Battlefield 4", 2013, "DICE", "First-person Shooter", true);
    VideoGame fifa12 ('P', 25, "FIFA 2012", 2011, "EA Vancouver", "Sports", false);
    VideoGame marioKart ('w', 20, "Mario Kart", 2008, "Nintendo", "Racing", false);
    VideoGame pokemon ('g', 15, "Pokemon Red and Blue", 1998, "Game Freak", "Role-playing", false);

    cout << "Welcome to the Video Game Collection Program" << endl;
    char selected = '0';

    bool select1 = false;
    bool select2 = false;
    bool select3 = false;
    bool select4 = false;

    string fileName = "VideoGames.csv";

    while (selected != '5')
    {
        cout << "\n\n\t\tVideo Games Menu\n\n";
        cout << "Items : " << VideoGame::num_games << endl;

        cout << "1. Enter data into the array manually" << endl;
        cout << "2. Load data from a CSV of XML file into the array" << endl;
        cout << "3. Print report of elements in the array" << endl;
        cout << "4. Generate a vector from the array and display the contents" << endl;
        cout << "5. Exit program" << endl;

        selected = getchar();

        if (VideoGame::num_games > 9)
        {
            cout << "The array is full --> Here are the contents : " << endl;
            myVideoGameCollection.printReport();
            break;
        }

        switch (selected)
        {
            case '1':   myVideoGameCollection.enterDataManually();
                        select1 = true;
                        break;

            case '2':   myVideoGameCollection.loadDataAutomatically(fileName);
                        select2 = true;
                        break;

            case '3':   myVideoGameCollection.printReport();
                        select3 = true;
                        break;

            case '4':   myVideoGameCollection.generateAndPrintVector();
                        select4 = true;
                        break;
        }

    cin.clear();
    cin.ignore(INT_MAX, '\n');
    }
    return 0;
}
