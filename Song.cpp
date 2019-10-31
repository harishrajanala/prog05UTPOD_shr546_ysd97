#include "UtPod.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>
#include "Song.h"
using namespace std;

Song::Song(){
    num=0;
    name="";
    person="";
}

Song::Song(string artist, string title, int size){

    num=size;
    name=title;
    person=artist;

}


//get modules
string Song::getTitle() const{

    return name;
}

string Song::getArtist() const{
    return person;
}

int Song::getSize() const{

    return num;
}

//set modules
void Song::setTitle(string title){

    name=title;   
}

void Song::setArtist(string artist){

    person=artist;
}
void Song::setSize(int size){

    num=size;
}

//operator modules
bool Song::operator == (Song const &rhs) const{

    if(rhs.name == name && rhs.num == num && rhs.person == person){
        return true;
    }
    return false;
}

bool Song::operator<(Song const &rhs) const{


        if(person == rhs.person){
            if(name == rhs.name){
                if(num < rhs.num){
                    return true;
                }
                else return false;
            }
            else return name<rhs.name;
        }
        else return person<rhs.person;
}

bool Song::operator>(Song const &rhs) const{


        if(rhs.person == person){
            if(rhs.name == name){
                if(rhs.num < num){
                    return true;
                }
                else return false;
            }
            else return name>rhs.name;
        }
        else return person>rhs.person;
}