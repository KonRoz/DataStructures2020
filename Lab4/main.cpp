/*
author: Konrad Rozanski
file: main.py

This file creates five instances of the VideoGame class, pushes them
into an instance of PQueue, and then displays them. The instances of 
VideoGame in the PQueue queue are then copied into a PStack instance
and then displayed again.
*/

#include <iomanip>
#include <string>
#include <iostream>
#include "VideoGame.h"
#include "PStack.h"
#include "PQueue.h"

using namespace std;

void print_labels()
{
    const char separator = ' ';
    const int stringWidth = 30;
    const int numWidth = 20;

    cout << left << setw(stringWidth) << setfill(separator) << "Title";
    cout << setw(numWidth) << setfill(separator) << "Price";
    cout << setw(stringWidth) << setfill(separator) << "Console";
    cout << setw(numWidth) << setfill(separator) << "Year of Release";
    cout << setw(stringWidth) << setfill(separator) << "Developer";
    cout << setw(stringWidth) << setfill(separator) << "Genre";
    cout << setw(stringWidth) << setfill(separator) << "Rating\n" << endl;
}

int main()
{
    cout << "\n\n\t\t\t\t\t\t\t\tWelcome to the Video Game Collection Program \n\n\n";

    PStack my_stack;
    PQueue my_queue;

    VideoGame game1 ('x',30,"Call of Duty: Black Ops 2",2012,"Treyarch","First-person Shooter",true);
    VideoGame game2 ('P',10,"Tetris",1990,"Alexey","Arcade",false);
    VideoGame game3 ('x',20,"The Legend of Zelda",1986,"Nintendo","Action-adventure",false);
    VideoGame game4 ('p',25,"Fifa 2012",2011,"EA Vancouver","Sports",false);
    VideoGame game5 ('w',19,"Mario Kart",2008,"Nintendo","Racing",false);

    my_queue.pushObjectIntoQueue(game1);
    my_queue.pushObjectIntoQueue(game2);
    my_queue.pushObjectIntoQueue(game3);
    my_queue.pushObjectIntoQueue(game4);
    my_queue.pushObjectIntoQueue(game5);
    
    cout << "Queue Contents : \n\n";
    cout << "Number of Items : " << my_queue.getNumGames() << "\n\n";
    print_labels();
    my_queue.showObjectsInQueue();

    my_queue.copyObjectsToStack(my_stack);

    cout << "\n\nStack Contents : \n\n";
    cout << "Number of Items : " << my_stack.getNumGames() << "\n\n";
    print_labels();
    my_stack.showObjectsOnStack();

    return 0;
}
