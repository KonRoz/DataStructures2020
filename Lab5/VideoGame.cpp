/*
author: Konrad Rozanski
file: VideoGame.cpp

This is the implementation file for VideoGame.h
*/

#include <iomanip>
#include <string>
#include <iostream>
#include "VideoGame.h"
using namespace std;

// declaring public static members
unsigned int VideoGame::num_games = 0;

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

VideoGame::VideoGame(char con, double pric, string tit, int relyear, string dev, string gen, double gt, bool ar)
{
	console = con;
	price = pric;
	title = tit;
	releaseYear = relyear;
	developer = dev;
	genre = gen;
	isAgeRestricted = ar;
    gameTime = gt;
}

// additional methods
void VideoGame::showGame()
{
    const char separator = ' ';
    const int stringWidth = 30;
    const int numWidth = 20;

	cout << left << setw(stringWidth) << setfill(separator) << title;
	cout << setw(numWidth) << setfill(separator) << price;

      // switch statement to output the right console based upon the char representing the console
	switch (console)
	{
		case 'x':
			cout << setw(stringWidth) << setfill(separator) << "Xbox";
			break;
		case 'p':
			cout << setw(stringWidth) << setfill(separator) << "Play Station";
			break;
		case 'P':
			cout << setw(stringWidth) << setfill(separator) << "PC";
			break;
		case 'w':
			cout << setw(stringWidth) << setfill(separator) << "Wii";
			break;
		case 'g':
			cout << setw(stringWidth) << setfill(separator) << "Game Boy";
			break;
		default:
			cout << setw(stringWidth) << setfill(separator) << "Sold Out";
	}
		
	cout << setw(numWidth) << setfill(separator) << releaseYear;
	cout << setw(stringWidth) << setfill(separator) << developer;
	cout << setw(stringWidth) << setfill(separator) << genre;
    cout << setw(numWidth) << setfill(separator) << gameTime;
	
	if (isAgeRestricted)
		cout << setw(stringWidth) << setfill(separator) << "**Age Restricted**" << endl;
	else
		cout << setw(stringWidth) << setfill(separator) << "NOT Age Restricted" << endl;
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

	cout << "- - - - - - - - - - - - - - - - - - -" << endl;
}

