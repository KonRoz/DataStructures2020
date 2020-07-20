/*
author: Konrad Rozanski
file: SportsGame.cpp

This is the implementation file for the SportsGame class
*/

#include <string>
#include <iomanip>
#include "VideoGame.h"
#include "CombatGame.h"

using namespace std;

SportsGame::SportsGame(char con, double pric, string tit, int relyear, string dev, string sp, int gamed)
{
    VideoGame(con, pric, tit, relyear, dev);

    sport = sp;
    gameDuration = gamed;
}

SportsGame::showValues()
{
    VideoGame::showGame();

    cout << setw(VideoGame::width) << "Sport : " << sport << setfill(VideoGame::separator) << "\n";
    cout << setw(VideoGame::width) << "Game Duration : " << gameDuration <<  setfill(VideoGame::separator) << "\n";
}
