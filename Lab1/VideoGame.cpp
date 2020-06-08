#include <string>
#include <iostream>
#include "VideoGame.h"
using namespace std;

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

VideoGame::showGame()
{
	cout << "Title: " << title << endl;
	cout << "Price: " << price << endl;
	cout << "Console; " << console << endl;
	cout << "Year of Release: " << releaseYear << endl;
	cout << "Developer: " << developer << endl;
	cout << "Genre: " << genre << endl;
	
	if (isAgeRestricted)
		cout << "**Age Restricted**" << endl;
	else
		cout << "NOT Age Restricted" << endl;

}

VideoGame::salePrice(double percentOff)
{
	price -= (0.10 * percentOff * price); 
	
	cout << percentOff << " Percent Off " << title << ": " <<  price << endl;
}

VideoGame::showGameCentury()
{
	if (releaseYear >= 2000)
		cout << "21st Century!" << endl;
	else if (releaseYear >= 1900)
		cout << "20th Century!" << endl;
	else
		cout << "Not Possible!" << endl;
}

