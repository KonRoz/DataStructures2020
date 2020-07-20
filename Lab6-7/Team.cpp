/*
author: Konrad Rozanski
file: Team.cpp

This is the implementation file for the Team class
*/

#include <iomanip>
#include <string>
#include "Team.h"

using namespace std;

Team::Team(string na, int ros, string cap, double cost)
{
    name = na;
    rosterSize = ros;
    teamCaptain = cap;
    teamCost = cost;
}

Team::showMembers()
{
    const char separator = ' ';
    const int width = 10;

    cout << setw(width) << "Team Name : " << name << "\n";
    cout << setw(width) << "Roster Size : " << rosterSize << "\n";
    cout << setw(width) << "Team Captain : " << teamCaptain << "\n";
    cout << setw(width) << "Roster Cost : " << teamCost << "\n";
}
