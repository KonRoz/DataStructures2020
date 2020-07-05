/*
author: Konrad Rozanski
file: PStack.h
classes: PStack

This is the header file for the PStack class.

It encapsulates a stack comprised of the VideoGame
class. There are two private members: the stack 
and an unsigned integer tracking the total number
of items inside the stack.

pushOnStack takes in a VideoGame and pushes it to
the VideoGameStack defined in the private members.

showObjectsOnStack displays all the VideoGames within
the stack without deleting them. This is done by creating
a copy of the VideoGameStack stack and then popping through 
it. 
*/

#ifndef PSTACK_H
#define PSTACK_H

#include <string>
#include <stack>
#include "VideoGame.h"

using namespace std;

class PStack
{

    private:

        unsigned int num_games = 0;
        stack <VideoGame> VideoGameStack;

    public:

        int getNumGames() { return num_games; }
        void pushOnStack(VideoGame video_game);
        void showObjectsOnStack();

};

#endif
