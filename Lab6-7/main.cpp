/*
author: Konrad Rozanski
file: main.cpp

This is the main file. It creates instances of CombatGame, SportsGame
and SoccerGame. An array is created and the instances are stored within 
it. This array is then iterated through and the values of the private 
members of all the instances stored in the array are displayed.
*/

#include <string>
#include <iostream>
#include <iomanip>
#include "SoccerGame.h"
#include "SportsGame.h"
#include "CombatGame.h"

using namespace std;

int main()
{
    cout << "\n\n\n\nSoccer Game #1 : \n\n"; 
    SoccerGame bayernVbarca ('x', 13, "FIFA 13", 2013, "EA", "Soccer", 90, 0, "Bayern Munich", 19, "Lahm", 2.2, "Real Madrid", 20, "Sergio Ramos", 4.1);
    bayernVbarca.showValues();

    cout << "\n\n\n\nSoccer Game #2 : \n\n";
    SoccerGame bayernVborussia ('p', 20, "FIFA 11", 2011, "EA", "Soccer", 90, 0, "Borussia Dortmund", 18, "Reus", 1.8, "Bayern Munich", 19, "Lahm", 2.2);
    bayernVborussia.showValues();

    cout << "\n\n\n\nSports Game : \n\n";
    SportsGame nflGame ('P', 5, "Madden 15", 2015, "DICE", "Football", 180);
    nflGame.showValues();

    cout << "\n\n\n\nCombat Game : \n\n";
    CombatGame callOfDuty ('x', 17, "Call of Duty", 2008, "Treyarch", true, 13);
    callOfDuty.showValues();

    // additional games to stick in the array
    SportsGame snowboarding ('g', 8, "Snowboarding", 2002, "Nintendo", "Snow Sports", 30);
    SportsGame basketball ('p', 30, "2K17", 2017, "2KSports", "Basketball", 48);
    CombatGame battlefield ('P', 25, "Battlefield 4", 2010, "DICE", true, 115);
    CombatGame supersmash ('g', 22, "Super Smash Bros", 1999, "Nintendo", false, 30);

    VideoGame* videogames[8];

    videogames[0] = &supersmash;
    videogames[1] = &battlefield;
    videogames[2] = &basketball;
    videogames[3] = &snowboarding;
    videogames[4] = &callOfDuty;
    videogames[5] = &nflGame;
    videogames[6] = &bayernVborussia;
    videogames[7] = &bayernVbarca;

    cout << "\n\n\n\n\t\t\t\tVideo Games Available\n\n\n";
    for (int i = 0; i < 8; i++)
    {
        videogames[i]->showValues();
    }

    return 0;
}
