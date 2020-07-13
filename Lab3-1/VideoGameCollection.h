/*
author: Konrad Rozanski
file: VideoGameCollection.h
classes: VideoGameCollection

This is the header file for VideoGameCollection class.

It contains three private members and the associated public 
members. The first is a struct which sets the structure for each
node within the linked list, VideoGameCollection. The last two 
private members, head and tail, are pointers to the first and
last element in the linked list respectively. A single default 
constructor is also included which sets the head and tail members
to null. A destructor is defined to delete the linked list elements
as they are dynamically allocated using new.

createNode creates a node within the linked list using the instance
of VideoGame that it is passed. It tacks this new node onto
the end of the linked list.

addVideoGameToEnd collects information from the user to create 
a new instance of VideoGame and passes it to createNode.

deleteVideoGameFromEnd deletes the element at the end of the 
linked list. 

loadDataAutomatically takes the passed CSV or XML file (located in
the same working directory) and parses it line by line to create 
the desired VideoGame object. These objects are then passed to 
createNode one by one.

printReport allows the user to print out a description of every
VideoGame object within the linked list. This is done by
utilizing the showGame method that comes packaged in each 
VideoGame object.
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
        void addVideoGameToEnd();
        void deleteVideoGameFromEnd();
        void loadDataAutomatically(const string &file_name);
        void printReport();
};

#endif
