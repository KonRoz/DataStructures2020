/*
author: Konrad Rozanski
file: Team.h
classes: Team

This is the header file for Team class.

It contains four private members. There are
also constructors (default and one with all 
arguments filled in).

showMembers displays the values of all four 
private members.
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

        // mutators
        void setName(string n) { name = n; }
        void setRosterSize(int r) { rosterSize = r;}
        void setTeamCaptain(string c) { teamCaptain = c; }
        void setTeamCost(double m) { teamCost = m; }

        // additional methods
        void showMembers();
};

#endif
