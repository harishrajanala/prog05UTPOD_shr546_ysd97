//
// Created by yashd on 10/28/2019.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H
#include <string>

using namespace std;

class Song {
    private:
        string artist;
        string title;
        int size;

    public:
        Song(string artist, string title, int size);

        string getArtist() const;
        string getTitle() const;
        int getSize() const;

        void setArtist(string artist);
        void setTitle(string title);
        void setSize(int size);

        void swap(Song &s1, Song &s2);

        bool operator <(Song const &rhs);
        bool operator >(Song const &rhs);
        bool operator ==(Song const &rhs);


};


#endif //UTPOD_SONG_H
