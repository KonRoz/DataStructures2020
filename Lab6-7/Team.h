/*
author: Konrad Rozanski
file: Team.h
classes: Team

This is the header file for Team class
*/

#ifndef TEAM_H
#define TEAM_H
#include <string>

using namespace std;

class Team
{

    private:

        string name;
        int rosterSize;
        string teamCaptain;
        double teamCost;

    public:

        // constructors
        Team() {}
        Team(string na, int ros, string cap, double cost);

        // accessors
        string getName() { return name; }
        int getRosterSize() { return rosterSize; }
        string getTeamCaptain() { return teamCaptain; }
        double getTeamCost() { return teamCost; }

        // additional methods
        void showMembers();
};

#endif
