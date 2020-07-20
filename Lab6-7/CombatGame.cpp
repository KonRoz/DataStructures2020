/*
author: Konrad Rozanski
file: CombatGame.cpp

This is the implementation file for CombatGame class
*/

#include <string>
#include <iomanip>
#include "VideoGame.h"
#include "CombatGame.h"

using namespace std;

CombatGame::CombatGame(char con, double pric, string tit, int relyear, string dev, bool ar, int nw)
{
    VideoGame(con, pric, tit, relyear, dev);

    isAgeRestricted = ar;
    numWeapons = nw;
}

CombatGame::showValues()
{
    VideoGame::showGame();

    cout << setw(VideoGame::width) << "Number of Weapons : " << numWeapons << setfill(VideoGame::separator) << "\n";

    if isAgeRestricted
    {
        cout << "**AGE RESTRICTED**\n"; 
    } else
    {
        cout << setw(VideoGame::width << "NOT AGE RESTRICTED\n";
    }
}
