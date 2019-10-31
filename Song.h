#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Song{

    private:
        string name;
        string person;
        int num;
    
    public:
        Song();
        Song(string artist,string title, int size);
        string getTitle() const;
        string getArtist() const;
        int getSize() const;
        void setTitle(string title);
        void setArtist(string artist);
        void setSize(int size);
        bool operator == (Song const &rhs) const;
        bool operator < (Song const &rhs) const;
        bool operator > (Song const &rhs) const;
};

#endif