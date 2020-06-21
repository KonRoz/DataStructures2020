/*
author: Konrad Rozanski
file: VideoGame.h
classes: VideoGame

This is the header file for for the VideoGame class.

It contains several private members describing a typical
video game sold by retail outlets. There are accessors 
and mutators associated with every private member. Likewise,
there are 6 constructors included --> one default constructor,
one constructor which takes 7 arguments. 

showGame displays the values of all 7 private members 

salePrice calculates the sale price of the video game 
based upon the percentage that it is passed. It displays
it and then stores it as the new price of the video game. 

showGameCentury uses the value of releaseYear to display
which century the game was developed in.
*/

#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include <string>

using namespace std;

class VideoGame
{

	private:

		char console;
		double price;
		string title;
		int releaseYear;
		string developer;
		string genre;
		bool isAgeRestricted;

	public:
        // public static members
        static int num_games;

		// constructors
		VideoGame();
		VideoGame(char con);
		VideoGame(char con, double pric);
		VideoGame(char con, double pric, string tit);
		VideoGame(char con, double pric, string tit, int relyear);
		VideoGame(char con, double pric, string tit, int relyear, string dev, string gen, bool ar);

		// accessors 
		char getConsole() { return console; }
		double getPrice() { return price; }
		string getTitle() { return title; }
		int getReleaseYear() { return releaseYear; }
		string getDeveloper() { return developer; }
		string getGenre() { return genre; }
		bool getIsAgeRestricted() { return isAgeRestricted; }

		// mutators
		void setConsole(char c) { console=c; }
		void setPrice(double p) { price=p; }
		void setTitle(string t) { title=t; }
		void setReleaseYear(int y) { releaseYear=y; }
		void setDeveloper(string d) { developer=d; }
		void setGenre(string g) { genre=g; }
		void setIsAgeRestricted(bool a) { isAgeRestricted=a; }

		// additional methods
		void showGame();
		void salePrice(double percentOff);
		void showGameCentury();	
};

#endif
