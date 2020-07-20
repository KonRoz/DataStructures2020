/*
author: Konrad Rozanski
file: Team.cpp

This is the implementation file for the Team class
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Team.h"
#include "VideoGame.h"

using namespace std;

Team::Team(string na, int ros, string cap, double cost)
{
    name = na;
    rosterSize = ros;
    teamCaptain = cap;
    teamCost = cost;
}

void Team::showMembers()
{
    cout << left << setw(VideoGame::width) << "\nTeam Name : " << name << setfill(VideoGame::separator) << "\n";
    cout << setw(VideoGame::width) << "Roster Size : " << rosterSize << setfill(VideoGame::separator) << "\n";
    cout << setw(VideoGame::width) << "Team Captain : " << teamCaptain << setfill(VideoGame::separator) << "\n";
    cout << setw(VideoGame::width) << "Team Cost : " << teamCost << setfill(VideoGame::separator) << " million \n";
}
