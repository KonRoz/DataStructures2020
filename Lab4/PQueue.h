/*
author: Konrad Rozanski
file: PQueue.h
classes: PQueue

This is the header file for the PQueue class.

It encapsulates a queue comprised of the VideoGame
class. There are two private members: the queue
and an unsigned integer tracking the total number 
of items inside the queue.

pushObjectIntoQueue takes in a VideoGame and pushes
it to the VideoGameQueue defined in the private members.

showObjectsInQueue displays all the VideoGames within 
the queue without deleting them. This is done by creating
a copy of the VideoGameQueue queue and then popping through
it.

copyObjectsToStack takes in a PStack and then copies the VideoGame
instances within VideoGameQueue to it. This is done without deleting
the objects within the VideoGameQueue.
*/

#ifndef PQUEUE_H
#define PQUEUE_H

#include <string>
#include <queue>
#include "VideoGame.h"
#include "PStack.h"

class PQueue
{

    private:

        unsigned int num_games = 0;
        queue <VideoGame> VideoGameQueue;

    public:

        int getNumGames(){ return num_games; }
        void pushObjectIntoQueue(VideoGame& video_game);
        void showObjectsInQueue();
        void copyObjectsToStack(PStack& video_game_stack);

};

#endif
