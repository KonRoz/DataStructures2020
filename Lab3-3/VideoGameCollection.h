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

modifyProductField allows the user to select a given product (via index)
and change a specified filed within it.

generateNewCSV allows the user to save the changes made over the course of the
run cycle in the same CSV that was used to initially populate several VideoGame
instances. The old CSV contents are overwritten when this occurs.

printFilteredReport allows the user to print a report of the VideoGame instances 
within VideoGameCollection using two specified fields.

The remaining methods are centered around sorting the list by both price and title.
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
            int nodeIndex;
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
        void modifyProductField();
        void generateNewCSV(const string &file_name);
        void printFilteredReport();

        void partition(VGNode* head, VGNode** front, VGNode** back);
        VGNode* mergeListsPrice(VGNode* a, VGNode* b);
        VGNode* mergeListsTitle(VGNode* a, VGNode* b);
        void mergeSortPrice(VGNode** source);
        void mergeSortTitle(VGNode** source);

        void generateTitleSortedList();
        void generatePriceSortedList();
};

#endif
