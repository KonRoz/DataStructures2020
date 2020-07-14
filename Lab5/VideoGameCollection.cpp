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

        VideoGame aVideoGame(row[0][0], stod(row[1]), row[2], stoi(row[3]), row[4], row[5], stod(row[6]), (row[7].compare("true") == 0) ? true : false);

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

void VideoGameCollection::recursiveBubbleSortDescription(int size)
{
    recursiveBubbleSort(videogames, size);
}

void VideoGameCollection::recursiveBubbleSort(VideoGame v_games[], int size)
{
    if (size == 1)
        return;

    for (int i = 0; i < size - 1; i++)
    {
        if (v_games[i].getPrice() > v_games[i + 1].getPrice())
            swapGames(v_games[i], v_games[i + 1]);
    }
    recursiveBubbleSort(v_games, size - 1);
}

void VideoGameCollection::swapGames(VideoGame &a, VideoGame &b)
{
    VideoGame temp = a;
    a = b;
    b = temp;
}

void VideoGameCollection::nonRecursiveBubbleSort(int size)
{
    for (int i = 0; i < size; i++)
    {
        int gameSwap = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (videogames[j].getReleaseYear() > videogames[j + 1].getReleaseYear())
            {
                swapGames(videogames[j], videogames[j + 1]);
                gameSwap = 1;
            }
        }
        if (!gameSwap)
            break;
    }
}

void VideoGameCollection::recursiveInsertionSortDescription(int n)
{
    recursiveInsertionSort(videogames, n);
}

void VideoGameCollection::recursiveInsertionSort(VideoGame games[], int n)
{
    if (n <= 1)
        return;
    recursiveInsertionSort(games, n - 1);
    VideoGame last = games[n - 1];
    int j = n - 2;

    while (j >= 0 && games[j].getTitle().compare(last.getTitle()) > 0)
    {
        games[j + 1] = games[j];
        j--;
    }
    games[j + 1] = last;
}

void VideoGameCollection::recursiveMergeSortDescription(int l, int r)
{
    recursiveMergeSort(videogames, l, r);
}

void VideoGameCollection::mergeGameArrays(VideoGame games[], int l, int m, int r)
{
    int n1, n2, i, j, k;
    n1 = m - l + 1;
    n2 = r - m;

    VideoGame L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = games[l + i];

    for (j = 0; j < n2; j++)
        R[j] = games[m + j + 1];

    i = 0, j = 0;

    for (k = l; i<n1 && j<n2; k++)
    {
        if(L[i].getGameTime() < R[j].getGameTime())
        {
            games[k] = L[i++];
        } else
        {
            games[k] = R[j++];
        }
    }

    while (i < n1)
    {
        games[k++] = L[i++];
    }

    while (j < n2)
    {
        games[k++] = R[j++];
    }
}

void VideoGameCollection::recursiveMergeSort(VideoGame games[], int l, int r)
{
    int m;
    if (l < r) 
    {
        m = (r + l) / 2;

        recursiveMergeSort(games, l, m);
        recursiveMergeSort(games, m + 1, r);
        mergeGameArrays(games, l, m, r);
    }
}
