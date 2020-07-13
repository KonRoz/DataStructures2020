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
    head = NULL;
    tail = NULL;
}

VideoGameCollection::~VideoGameCollection()
{
    VGNode* current = head;

    while (current != NULL)
    {
        VGNode* next = current->next;
        delete current;
        current = next;
    }

    head = NULL;
}

void VideoGameCollection::createNode (const VideoGame &video_game)
{
    // This might have to be new VGNode() with no parens
    VGNode* temp = new VGNode;
    temp->videogame = video_game;
    temp->next = NULL;
    temp->nodeIndex = VideoGame::num_games;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
    VideoGame::num_games++;
}

void VideoGameCollection::addVideoGameToEnd()
{
    char console;
    double price;
    string title;
    int releaseYear;
    string developer;
    string genre;
    bool isAgeRestricted;

    cout << "\n\nEnter Console --> x(box), p(lay station), P(C), w(ii), g(ame boy) : ";
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

    VideoGame video_game (console, price, title, releaseYear, developer, genre, isAgeRestricted);
    createNode(video_game);
}

void VideoGameCollection::deleteVideoGameFromEnd()
{
    if (head == NULL)
    {
        cout << "The list is empty\n";
    }
    else if (head->next == NULL)
    {
        delete head;
    } 
    else 
    {
        VGNode* second_last = head;

        while (second_last->next->next != NULL)
        {
            second_last = second_last->next;
        }

        delete (second_last->next);

        second_last->next = NULL;
        tail = second_last;
    }
    VideoGame::num_games--;
}

void VideoGameCollection::loadDataAutomatically(const string &file_name)
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

        createNode(aVideoGame);

        cout << "LINE WAS READ : (" << line << ")"  << endl;
    }
    if (fileIn.bad())
    {
        cout << "An IO error occured\n";
    } 
    else if (!fileIn.eof())
    {
        cout << "A format error occured\n";
    } 
    else
    {
        cout << endl << "Records Read!" << endl;
    }
    fileIn.close();
}

void VideoGameCollection::printReport()
{
    // Using the showGame method that was implemented in Lab 1

    cout << "These are the games available for purchase : " << endl;
    cout << " - - - - - - - - - - - - - - " << endl;

    VGNode* temp = new VGNode;
    temp = head;

    while (temp != NULL)
    {
        cout << to_string(temp->nodeIndex) << "\n\n";
        temp->videogame.showGame();
        temp = temp->next;
    }
}

void VideoGameCollection::modifyProductField()
{
    int gameToBeModified;
    string fieldToBeModified;

    VGNode* temp = new VGNode;
    temp = head;

    cout << "Input Game Index : ";
    cin >> gameToBeModified;

    cout << "\nInput Game Field (Title, Price, Console, Release, Developer, Genre, Restriction) : ";
    cin >> fieldToBeModified;

    while (temp->nodeIndex != gameToBeModified)
    {
        temp = temp->next;
    }

    if ("Title" == fieldToBeModified)
    {
        string title;
        cout << "Enter New Title : ";
        cin >> title;
        temp->videogame.setTitle(title);
    } else if ("Price" == fieldToBeModified)
    {
        int price;
        cout << "Enter New Price : ";
        cin >> price;
        temp->videogame.setPrice(price);
    } else if ("Console" == fieldToBeModified)
    {
        char console;
        cout << "Enter New Console : ";
        cin >> console;
        temp->videogame.setConsole(console);
    } else if ("Release" == fieldToBeModified)
    {
        int yearOfRelease;
        cout << "Enter New Year of Release : ";
        cin >> yearOfRelease;
        temp->videogame.setReleaseYear(yearOfRelease);
    } else if ("Developer" == fieldToBeModified)
    {
        string developer;
        cout << "Enter New Developer : ";
        cin >> developer;
        temp->videogame.setDeveloper(developer);
    } else if ("Genre" == fieldToBeModified)
    {
        string genre;
        cout << "Enter New Genre : ";
        cin >> genre;
        temp->videogame.setGenre(genre);
    } else if ("Restriction" == fieldToBeModified)
    {
        bool ageRestricted;
        cout << "Enter New Age Restriction : ";
        cin >> ageRestricted;
        temp->videogame.setIsAgeRestricted(ageRestricted);
    } else
    {
        cout << "\nPlease Input Valid Field Name\n";
    }

    cout << "\n\nModified Game\n\n";
    temp->videogame.showGame();
}

void VideoGameCollection::generateNewCSV(const string &file_name)
{
    ofstream myfile;
    myfile.open(file_name);

    VGNode* temp = new VGNode;
    temp = head;

    while (temp != NULL)
    {
        string title = temp->videogame.getTitle();
        string price = to_string(temp->videogame.getPrice());
        string console(1, temp->videogame.getConsole());
        string release = to_string(temp->videogame.getReleaseYear());
        string developer = temp->videogame.getDeveloper();
        string genre = temp->videogame.getGenre();
        string restriction = temp->videogame.getIsAgeRestricted() ? "true" : "false";
        string the_line = "" + console + "," + price + "," + title + "," + release + "," + developer + "," + genre + "," + restriction + "\n";

        myfile << the_line;

        temp = temp->next;
    }
    myfile.close();
}

void VideoGameCollection::printFilteredReport()
{
    string filter1;
    string filter2;

    VGNode* temp = new VGNode;
    temp = head;

    cout << "\nField Filters :  Title, Price, Console, Release, Developer, Genre, Restriction\n";

    cout << "Input First Filter : ";
    cin >> filter1;

    cout << "Input Second Filter : ";
    cin >> filter2;

    while (temp != NULL)
    {
        cout << to_string(temp->nodeIndex) << "\n\n";
        temp->videogame.showGame(filter1, filter2);
        temp = temp->next;
    }
}


