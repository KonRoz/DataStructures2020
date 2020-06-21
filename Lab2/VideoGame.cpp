/*
author: Konrad Rozanski
file: VideoGame.cpp

This is the implementation file for VideoGame.h
*/

#include <string>
#include <iostream>
#include "VideoGame.h"
using namespace std;

// declaring public static members
int VideoGame::num_games = 0;

// constructors
VideoGame::VideoGame() {}

VideoGame::VideoGame(char con): console(con) {}

VideoGame::VideoGame(char con, double pric): console(con), price(pric) {}

VideoGame::VideoGame(char con, double pric, string tit): console(con), price(pric), title(tit) {}

VideoGame::VideoGame(char con, double pric, string tit, int relyear)
{
	console = con;
	price = pric;
	title = tit;
	releaseYear = relyear;
}

VideoGame::VideoGame(char con, double pric, string tit, int relyear, string dev, string gen, bool ar)
{
	console = con;
	price = pric;
	title = tit;
	releaseYear = relyear;
	developer = dev;
	genre = gen;
	isAgeRestricted = ar;
}

// additional methods
void VideoGame::showGame()
{
	cout << "Title: " << title << endl;
	cout << "Price: " << price << " dollars" << endl;

      // switch statement to output the right console based upon the char representing the console
	switch (console)
	{
		case 'x':
			cout << "Console: Xbox" << endl;
			break;
		case 'p':
			cout << "Console: Play Station" << endl;
			break;
		case 'P':
			cout << "Console: PC" << endl;
			break;
		case 'w':
			cout << "Console: Wii" << endl;
			break;
		case 'g':
			cout << "Console: Game Boy" << endl;
			break;
		default:
			cout << "Sold Out" << endl;
	}
		
	cout << "Year of Release: " << releaseYear << endl;
	cout << "Developer: " << developer << endl;
	cout << "Genre: " << genre << endl;
	
	if (isAgeRestricted)
		cout << "**Age Restricted**" << endl;
	else
		cout << "NOT Age Restricted" << endl;

	cout << " - - - - - - - - - - - - - - " << endl;

}

void VideoGame::salePrice(double percentOff)
{
	price = price - (0.01 * percentOff * price); 
	
	cout << percentOff << " Percent Off " << title << ": " <<  price << " dollars" << endl;
	
	cout << " - - - - - - - -- - - - - - " << endl;
}

void VideoGame::showGameCentury()
{
	if (releaseYear >= 2000)
		cout << title << ": 21st Century!" << endl;
	else if (releaseYear >= 1900)
		cout << title << ": 20th Century!" << endl;
	else
		cout << title << ": Not Possible!" << endl;

	cout << " - - - - - - - - - - - - - " << endl;
}

