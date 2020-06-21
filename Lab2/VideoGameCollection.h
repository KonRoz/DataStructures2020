#ifndef VIDEOGAMESCOLLECTION_H
#define VIDEOGAMESCOLLECTION_H
#include <string>
#include "VideoGame.h"

using namespace std; 

class VideoGameCollection
{
    private:

        VideoGame videogames[10];

    public:

        // Constructor
        VideoGameCollection();

        // Additional Methods
        void addVideoGame(VideoGame video_game);
        void enterDataManually();
        void loadDataAutomatically(string file_name);
        void printReport();
        void generateAndPrintVector();
};

#endif
