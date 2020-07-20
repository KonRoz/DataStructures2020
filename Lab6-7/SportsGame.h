/*
author: Konrad Rozanski
file: SportsGame.h
classes: SportsGame

This is the header file for the SportsGame class.

There are two private members. Two constructors are 
also included (one default and one with all arguments
filled in).

showValues is the implementation of the abstract method 
showValues in the VideoGame class. 
*/

#ifndef SPORTSGAMES_H
#define SPORTSGAMES_H

#include <string>
#include "VideoGame.h"

using namespace std;

class SportsGame : public VideoGame
{
    private:
        string sport;
        int gameDuration;

    public:
        // constructors 
        SportsGame() {}
        SportsGame(char con, double pric, string tit, int relyear, string dev, string sp, int gamed);

        // accessors
        string getSport() { return sport; }
        int getGameDuration() { return gameDuration; }

        // mutators
        void setSport(string s) { sport = s; }
        void setGameDuration(int d) { gameDuration = d; }

        // additional methods
        void showValues();
};

#endif
