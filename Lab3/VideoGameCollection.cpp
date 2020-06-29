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
    // no nodes created initially

    head = NULL;
    tail = NULL;
}

VideoGameCollection::~VideoGameCollection()
{
    // destructor for the linked list
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
}

void VideoGameCollection::addVideoGameToEnd(const VideoGame &video_game)
{
    // adding the video game to the end of the linked list
    createNode(video_game);
}

void VideoGameCollection::deleteVideoGame(const VideoGame &video_game)
{
    // delete video game
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

        addVideoGameToEnd(aVideoGame);

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
        temp->videogame.showGame()
        temp = temp->next;
    }
}


