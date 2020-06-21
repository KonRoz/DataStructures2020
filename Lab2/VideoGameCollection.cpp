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
    // make sure to modify code for 5 arguments
    fstream fileIn;
    fileIn.open(file_name.c_str(), ios::in);

    vector<string> row;
    string line="", word="";

    while (!fileIn.eof())
    {
        getline(fileIn, line);

        row.clear();

        istringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        cout << row[0] << ',';
        cout << row[1] << ',';
        cout << row[2] << ',';
        cout << row[3] << ',';
        cout << row[4] << ',';
        cout << row[5] << "\n";

        VideoGame aVideoGame(row[0], stoi(row[1]), stod(row[2]), row[3][0], (row[4].compare("true") == 0) ? true : false);

        addVideoGame(aVideoGame);

        cout << "LINE : " << line << endl << endl;
    }
    cout << endl << "Records Read!" << endl;
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
    vector<VideoGame> videoGameVector;

    // moving elements in the array to the vector
    for (VideoGame game: videogames)
    {
        videoGameVector.push_back(game);
    }

    cout << "Displaying the elements in the vector : " << endl;

    // displaying the elements contained within the vector
    for (VideoGame game: videoGameVector)
    {
        game.showGame();
    }
}
