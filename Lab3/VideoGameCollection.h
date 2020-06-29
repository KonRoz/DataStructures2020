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

generateAndPrintVector takes the current objects stored in the 
videogames array and creates copies and stores them in a vector.
The vector's contents are then displayed using a process similar
to that in printReport.
*/

#ifndef VIDEOGAMESCOLLECTION_H
#define VIDEOGAMESCOLLECTION_H
#include <string>
#include "VideoGame.h"

using namespace std; 

class VideoGameCollection
{
    private:

        struct VGNode
        {
            VGNode* next;
            VideoGame videogame;
        };

        VGNode* head;
        VGNode* tail;

    public:

        // Constructor
        VideoGameCollection();

        // Destructor
        ~VideoGameCollection();

        // Additional Methods
        void createNode (const VideoGame &video_game);
        void addVideoGameToEnd(const VideoGame &video_game);
        void deleteVideoGame(const VideoGame &video_game);
        void loadDataAutomatically(const string &file_name);
        void printReport() const;
};

#endif
