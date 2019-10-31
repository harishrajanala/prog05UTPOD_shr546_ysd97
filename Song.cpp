//
// Created by yashd on 10/28/2019.
//

#include "Song.h"
#include <string>
using namespace std;

    Song::Song(string artist, string title, int size){
        this->artist=artist;
        this->title=title;
        this->size=size;
    }

    string Song::getArtist() const { return artist; }
    string Song::getTitle() const { return title; }
    int Song::getSize() const { return size; }

    void Song::setArtist(string artist) {
        this->artist=artist;
    }
    void Song::setTitle(string title) {
        this->title=title;
    }
    void Song::setSize(int size) {
        this->size=size;
    }

    void Song::swap(Song &s1, Song  &s2) {
        Song temp = s1;
        s1 = s2;
        s2 = temp;
    }

    bool Song::operator <(Song const &rhs) {
        if(artist == rhs.artist) {
            if(title == rhs.title)
                return size > rhs.size;
            return title < rhs.title;
        }
        return artist < rhs.artist;
    }
    bool Song::operator >(Song const &rhs) {
        if(artist == rhs.artist) {
            if(title == rhs.title)
                return size > rhs.size;
            return title > rhs.title;
        }
        return artist > rhs.artist;
    }
    bool Song::operator ==(Song const &rhs) {
        return (artist == rhs.artist &&
                title == rhs.title &&
                size == rhs.size);
    }
