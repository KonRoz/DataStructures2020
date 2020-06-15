/*
author: Konrad Rozanski
file: main.py

Testing VideoGame and Menu class by instantiating 6 objects using the various
constructors and calling the additional methods
*/

#include <string>
#include <iostream>
#include "VideoGame.h"
#include "Menu.h"
using namespace std;

int main()
{
    // instantiating various video games
    VideoGame callOfDutyBlackOps2('x', 30, "Call of Duty: Black Ops 2", 2012, "Treyarch", "First-person Shooter", true);
    VideoGame zelda ('x', 10, "The Legend of Zelda", 1986, "Nintendo", "Action-adventure", false);
    VideoGame battlefield4 ('p', 40, "Battlefield 4", 2013, "DICE", "First-person Shooter", true);
    VideoGame fifa12 ('P', 25, "FIFA 2012", 2011, "EA Vancouver", "Sports", false);
    VideoGame marioKart ('w', 20, "Mario Kart", 2008, "Nintendo", "Racing", false);
    VideoGame pokemon ('g', 15, "Pokemon Red and Blue", 1998, "Game Freak", "Role-playing", false);

    return 0;
}
