/*
author: Konrad Rozanski
file: CombatGame.h
classes: CombatGame

This is the header file for the CombatGame class
*/

#ifndef COMBATGAME_H
#define COMBATGAME_H

#include <string>
#include <iomanip>
#include "VideoGame.h"

using namespace std;

class CombatGame : public VideoGame
{

    private:

        bool isAgeRestricted;
        int numWeapons;

    public:

        // constructors
        CombatGame() {}
        CombatGame(char con, double pric, string tit, int relyear, string dev, bool ar, int nw);

        // accessors
        bool getIsAgeRestricted() { return isAgeRestricted; }
        int getNumWeapons() { return numWeapons; }

        // mutators
        void setIsAgeRestricted(bool ar) { isAgeRestricted = ar; }
        void setNumWeapons(int nw) { numWeapons = nw; }

        // additional methods
        void showValues();
};

#endif
