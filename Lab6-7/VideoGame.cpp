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
void VideoGame::showGame()
{
    cout << "-------------------------------------";
	cout << left << setw(VideoGame::width) << "\nTitle : " << title << setfill(VideoGame::separator) << "\n";
	cout << setw(VideoGame::width) << "Price : " << price << setfill(VideoGame::separator) << "\n";

    string con; 

    // switch statement to output the right console based upon the char representing the console
	switch (console)
	{
		case 'x':
			con = "Xbox";
			break;
		case 'p':
			con = "Play Station";
			break;
		case 'P':
			con = "PC";
			break;
		case 'w':
			con = "Wii";
			break;
		case 'g':
			con = "Game Boy";
			break;
		default:
			con = "Sold Out";
	}

	cout << setw(VideoGame::width) << "Console : " << con << setfill(VideoGame::separator) << "\n";
		
	cout << setw(VideoGame::width) << "Release Year : " << releaseYear << setfill(VideoGame::separator) << "\n";
	cout << setw(VideoGame::width) << "Developer : " << developer << setfill(VideoGame::separator) << "\n";
}
