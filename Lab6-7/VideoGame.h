/*
author: Konrad Rozanski
file: VideoGame.h
classes: VideoGame

This is the header file for the VideoGame class. It 
is an abstract class.

It contains several private members describing a typical
video game sold by retail outlets. There are accessors 
and mutators associated with every private member. Likewise,
there are 2 constructors included --> one default constructor,
and a one constructor which takes 5 arguments.

showValues is a pure virtual method that is to be implemented
in all inheriting classes. 

showGame is a virtual method that displays the values of all 
5 private members.
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

	public:

        // public static members
        static unsigned int width;
        static char separator;

		// constructors
		VideoGame() {}
		VideoGame(char con, double pric, string tit, int relyear, string dev);

		// accessors 
		char getConsole() { return console; }
		double getPrice() { return price; }
		string getTitle() { return title; }
		int getReleaseYear() { return releaseYear; }
		string getDeveloper() { return developer; }

		// mutators
		void setConsole(char c) { console=c; }
		void setPrice(double p) { price=p; }
		void setTitle(string t) { title=t; }
		void setReleaseYear(int y) { releaseYear=y; }
		void setDeveloper(string d) { developer=d; }

		// additional methods
        virtual void showValues() = 0;
		virtual void showGame();
};

#endif
