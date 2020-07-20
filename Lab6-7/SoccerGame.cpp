/*
author: Konrad Rozanski
file: SoccerGame.cpp

This is the implementation file for SoccerGame class
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "SoccerGame.h"
#include "Team.h"

SoccerGame::SoccerGame(char con, double pric, string tit, int relyear, string dev, string sp, int gamed,
        int nred, string hn, int hr, string ht, double hc, string at, int aro, string atc, double ac) :
    SportsGame(con, pric, tit, relyear, dev, sp, gamed)
{
    numRedCards = nred;

    homeTeam = Team(hn, hr, ht, hc);

    awayTeam = Team(at, aro, atc, ac);
}

void SoccerGame::showValues()
{
    SportsGame::showValues();

    cout << setw(VideoGame::width) << "Red Cards in Game : " << numRedCards << "\n";

    cout << setw(VideoGame::width) << "\n\n\t\tHOME TEAM\n\n";
    homeTeam.showMembers();

    cout << setw(VideoGame::width) << "\n\n\t\tAWAY TEAM\n\n";
    awayTeam.showMembers();
}
