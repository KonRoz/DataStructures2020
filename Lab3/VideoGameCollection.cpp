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
        temp->videogame.showGame();
        temp = temp->next;
    }
}


