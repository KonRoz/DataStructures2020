/*
author: Konrad Rozanski
file: VideoGameCollection.cpp

This is the implementation file for VideoGameCollection.h
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "VideoGameCollection.h"

using namespace std;

VideoGameCollection::VideoGameCollection()
{
    for (int game_item; game_item < 10; game_item++)
        videogames [game_item] = *(new VideoGame());
}

void VideoGameCollection::addVideoGame(VideoGame video_game)
{
    videogames [VideoGame::num_games] = video_game;
    ++VideoGame::num_games;
}

void VideoGameCollection::enterDataManually()
{
    char console;
    double price;
    string title;
    int releaseYear;
    string developer;
    string genre;
    bool isAgeRestricted;

    cout << "Enter Console --> x(box), p(lay station), P(C), w(ii), g(ame boy) : ";
    cin >> console;

    cout << "Enter Price : ";
    cin >> price;

    cout << "Enter Title : ";
    cin >> title;

    cout << "Enter Release Year : ";
    cin >> releaseYear;

    cout << "Enter Developer : ";
    cin >> developer;

    cout << "Enter Genre : ";
    cin >> genre;

    cout << "Enter Age Restriction --> 1(true), 0(false) : ";
    cin >> isAgeRestricted;

    VideoGame game (console, price, title, releaseYear, developer, genre, isAgeRestricted);
    videogames[VideoGame::num_games++] = game;
}

void VideoGameCollection::loadDataAutomatically(string file_name)
{
    fstream fileIn;
    fileIn.open(file_name, ios::in);

    vector<string> row;
    string line;
    string word;

    while (getline(fileIn, line))
    {
        row.clear();

        istringstream s (line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        VideoGame aVideoGame(row[0][0], stod(row[1]), row[2], stoi(row[3]), row[4], row[5], (row[6].compare("true") == 0) ? true : false);

        addVideoGame(aVideoGame);

        cout << "LINE WAS READ : (" << line << ")"  << endl;
    }
    if (fileIn.bad())
    {
        cout << "An IO error occured\n";
    } else if (!fileIn.eof())
    {
        cout << "A format error occured\n";
    } else
    {
        cout << endl << "Records Read!" << endl;
    }
}

void VideoGameCollection::printReport()
{
    // Using the showGame method that was implemented in Lab 1

    cout << "These are the games available for purchase : " << endl;
    cout << " - - - - - - - - - - - - - - " << endl;

    for (int i = 0; i < VideoGame::num_games; i++)
    {
        cout << "Game number : " << i << endl;
        videogames[i].showGame();
    }
}

void VideoGameCollection::generateAndPrintVector()
{
    cout << "Generating vector from array...\n";

    vector<VideoGame> videoGameVector;
    
    // moving elements in the array to the vector
    for (int i = 0; i < VideoGame::num_games; i++)
    {
        videoGameVector.push_back(videogames[i]);
    }

    cout << "\n\n\t\tDISPLAYING VECTOR ELEMENTS\n\n";
    cout << ": : : : : : : : : : : : : : : : : : : : \n";

    // displaying the elements contained within the vector
    for (VideoGame game: videoGameVector)
    {
        cout << "* * * * * * * * * * * * * * * * * * * *\n";
        game.showGame();
        cout << "* * * * * * * * * * * * * * * * * * * *\n";
    }
}
