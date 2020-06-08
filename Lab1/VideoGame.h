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
