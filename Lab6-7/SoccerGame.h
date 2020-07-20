/*
author: Konrad Rozanski
file: SoccerGame.h
classes: SoccerGame

This is the header file for SoccerGame class.

There are three private members. Two constructors
are included (one default and the other with all
arguments filled in).

showValues is the implementation of the abstract method
showValues in VideoGame.
*/

#ifndef SOCCERGAME_H
#define SOCCERGAME_H
#include <string>
#include "SportsGame.h"
#include "Team.h"

class SoccerGame : public SportsGame
{
    private:
        int numRedCards;
        Team homeTeam;
        Team awayTeam;

    public:
        // constructors
        SoccerGame() {}
        SoccerGame(char con, double pric, string tit, int relyear, string dev, string sp, int gamed, 
                int nred, string hn, int hr, string ht, double hc, string at, int aro, string atc, double ac);

        // accessors
        int getNumRedCards() { return numRedCards; }
        Team getHomeTeam() { return homeTeam; }
        Team getAwayTeam() { return awayTeam; }

        // mutators 
        void setNumRedCards(int c) { numRedCards = c; }
        void setHomeTeam(Team ht) { homeTeam = ht; }
        void setAwayTeam(Team at) { awayTeam = at; }

        // additional methods
        void showValues();
};

#endif
