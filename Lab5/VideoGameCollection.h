/*
author: Konrad Rozanski
file: VideoGameCollection.h
classes: VideoGameCollection

This is the header file for VideoGameCollection class.

It contains one private member and the associated public 
members. The one private member is a standard array of size 10 
(as dictated in the assignment). A single default constructor 
is also included.

addVideoGame adds the passed VideoGame object to the standard 
array called videogames.

enterDataManually allows the user to fill in the fields required
to create a VideoGame object. The associated prompts are included.

loadDataAutomatically takes the passed CSV or XML file (located in
the same working directory) and parses it line by line to create 
the desired VideoGame object. These objects are then stored in the 
videogames array.

printReport allows the user to print out a description of every
VideoGame object within the videogames array. This is done by
utilizing the showGame method that comes packaged in each 
VideoGame object.

The remaining methods are implementation of iterative sort algorithms 
(i.e. Bubble Sort) and recursive sort algorithms (i.e. Bubble Sort,
Insertion Sort, and Merge Sort).
*/

#ifndef VIDEOGAMESCOLLECTION_H
#define VIDEOGAMESCOLLECTION_H
#include <string>
#include "VideoGame.h"

using namespace std; 

class VideoGameCollection
{
    private:

        VideoGame videogames[24];

    public:

        // Constructor
        VideoGameCollection();

        // Additional Methods
        void addVideoGame(VideoGame video_game);
        void loadDataAutomatically(string file_name);
        void printReport();

        //Bubble Sort
        void recursiveBubbleSortDescription(int size);
        void recursiveBubbleSort(VideoGame v_games[],int size);

        void swapGames(VideoGame &a, VideoGame &b);
        void nonRecursiveBubbleSort(int size);

        void recursiveInsertionSortDescription(int n);
        void recursiveInsertionSort(VideoGame games[], int n);

        void recursiveMergeSortDescription(int l, int r);
        void mergeGameArrays(VideoGame games[], int l, int m, int r);
        void recursiveMergeSort(VideoGame games[], int l, int r);
};

#endif
