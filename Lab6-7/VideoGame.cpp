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
unsigned int VideoGame::width = 20;
char VideoGame::separator = ' ';

// constructors
VideoGame::VideoGame(char con, double pric, string tit, int relyear, string dev)
{
	console = con;
	price = pric;
	title = tit;
	releaseYear = relyear;
	developer = dev;
}

// additional methods
virtual void VideoGame::showGame()
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
}
