/*
author: Konrad Rozanski
file: PStack.cpp

This is the implementation file for PStack classes
*/

#include <stack>
#include "PStack.h"
#include "VideoGame.h"

void PStack::pushOnStack(VideoGame video_game)
{
    VideoGameStack.push(video_game);
    num_games++;
}

void PStack::showObjectsOnStack()
{
    stack <VideoGame> print_stack (VideoGameStack);

    while (!print_stack.empty())
    {
        VideoGame video_game = print_stack.top();
        video_game.showGame();
        print_stack.pop();
    }
}
