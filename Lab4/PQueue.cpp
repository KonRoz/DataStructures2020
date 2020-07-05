/*
author: Konrad Rozanski
file: PQueue.cpp

This is the implementation file for the PQueue class.
*/

#include <iostream>
#include <queue>
#include "PQueue.h"
#include "VideoGame.h"
#include "PStack.h"

void PQueue::pushObjectIntoQueue(VideoGame& video_game)
{
    VideoGameQueue.push(video_game);
    num_games++;
}

void PQueue::showObjectsInQueue()
{
    queue <VideoGame> printing_queue (VideoGameQueue);

    while (!printing_queue.empty())
    {
        VideoGame video_game = printing_queue.front();
        video_game.showGame();
        printing_queue.pop();
    }
}

void PQueue::copyObjectsToStack(PStack& video_game_stack)
{
    queue <VideoGame> copy_queue (VideoGameQueue);

    while (!copy_queue.empty())
    {
        VideoGame element_to_push = copy_queue.front();
        video_game_stack.pushOnStack(element_to_push);
        copy_queue.pop();
    }
}
