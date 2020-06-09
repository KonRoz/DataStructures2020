/* 
author: Konrad Rozanski

Testing VideoGame class by instantiating 6 objects using the various
constructors and calling the additional methods
*/

#include <string>
#include <iostream>
#include "VideoGame.h"
using namespace std;

int main()
{
    // instantiating various video games
	VideoGame callOfDutyBlackOps2;
	VideoGame zelda ('x');
	VideoGame battlefield4 ('p', 40);
	VideoGame fifa12 ('P', 25, "FIFA 2012");
	VideoGame marioKart ('w', 20, "Mario Kart", 2008);
	VideoGame pokemon ('g', 15, "Pokemon Red and Blue", 1998, "Game Freak", "Role-playing", false); 

	callOfDutyBlackOps2.setConsole('x');
	callOfDutyBlackOps2.setPrice(30);
	callOfDutyBlackOps2.setTitle("Call of Duty: Black Ops 2");
	callOfDutyBlackOps2.setReleaseYear(2012); 
	callOfDutyBlackOps2.setDeveloper("Treyarch");
	callOfDutyBlackOps2.setGenre("First-person Shooter");
	callOfDutyBlackOps2.setIsAgeRestricted(true); 

	zelda.setPrice(10);
	zelda.setTitle("The Legend of Zelda");
	zelda.setReleaseYear(1986);
	zelda.setDeveloper("Nintendo");
	zelda.setGenre("Action-adventure");
	zelda.setIsAgeRestricted(false);

	battlefield4.setTitle("Battlefield 4");
	battlefield4.setReleaseYear(2013);
	battlefield4.setDeveloper("DICE");
	battlefield4.setGenre("First-person Shooter");
	battlefield4.setIsAgeRestricted(true);

	fifa12.setReleaseYear(2011);
	fifa12.setDeveloper("EA Vancouver");
	fifa12.setGenre("Sports");
	fifa12.setIsAgeRestricted(false);

	marioKart.setDeveloper("Nintendo");
	marioKart.setGenre("Racing");
	marioKart.setIsAgeRestricted(false);
	
    // Testing additional methods 
 	cout << "Available Games\n" << endl;
	callOfDutyBlackOps2.showGame();
	zelda.showGame();
	battlefield4.showGame();
	fifa12.showGame();
	marioKart.showGame();
	pokemon.showGame();

	cout << "Sale Prices\n" << endl;
	callOfDutyBlackOps2.salePrice(20);
	zelda.salePrice(20);
	battlefield4.salePrice(20);
	fifa12.salePrice(20);
	marioKart.salePrice(20);
	pokemon.salePrice(20);

	cout << "Which Century?\n" << endl;
	callOfDutyBlackOps2.showGameCentury();
	zelda.showGameCentury();
	battlefield4.showGameCentury();
	fifa12.showGameCentury();
	marioKart.showGameCentury();
	pokemon.showGameCentury();

	return 0;

}
