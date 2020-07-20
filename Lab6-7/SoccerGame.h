/*
author: Konrad Rozanski
file: SoccerGame.h
classes: SoccerGame

This is the header file for SoccerGame class
*/

#ifndef SOCCERGAME_H
#define SOCCERGAME_H
#include "SportsGame.h"
#include "Team.h"

class SoccerGame : public SportsGame
{

    private:

        int numRedCards;
        Team homeTeam;
        Team awayTeam;

    public:

        // public members
};

#endif
