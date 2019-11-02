//DOCUMENT HERE

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//UtPod class declaration
class UtPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;
      
      struct SongNode
      {
         Song s;
         SongNode *next;
      };
      
      SongNode *songs;  //the head pointer
      
      int memSize;

      int getSongCount();

   
   public:
      UtPod();

      UtPod(int size);

      int addSong(Song const &s);

      int removeSong(Song const &s);

      void shuffle();

      void showSongList();

      void sortSongList();

      void clearMemory();

      int getTotalMemory() {
         return memSize;
      }

      int getRemainingMemory();
      
      ~UtPod();
 
};



#endif