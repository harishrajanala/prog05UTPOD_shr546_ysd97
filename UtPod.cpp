//DOCUMENT HERE

#include "UtPod.h"
#include "Song.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;

        //Default constructor
        //set the memory size to MAX_MEMORY
        UtPod::UtPod() {
            memSize = MAX_MEMORY;
            songs = NULL;
            unsigned int currentTime =  (unsigned)time(0);
            srand(currentTime);
        }

        //Constructor with size parameter
        //The user of the class will pass in a size.
        //If the size is greater than MAX_MEMORY or less than or equal to 0,
        //set the size to MAX_MEMORY.
        UtPod::UtPod(int size) {
            if((size > MAX_MEMORY) || (size <=0))
                memSize = MAX_MEMORY;
            else
                memSize=size;
            songs = NULL;
            unsigned int currentTime =  (unsigned)time(0);
            srand(currentTime);
        }

        /* FUNCTION - int addSong
         * attempts to add a new Song to the UtPod
             o returns a 0 if successful
             o returns -1 if not enough memory to add the Song

         precondition: s is a valid Song

         input parms -

         output parms -
        */

        int UtPod::addSong(Song const &s) {
            if(s.getSize() > getRemainingMemory())
                return NO_MEMORY;
            else
            {
               SongNode* n;
               n->s=s;
               n->next=songs;
               songs = n;
               return SUCCESS;
            }
        }


        /* FUNCTION - int removeSong
         * attempts to remove a Song from the UtPod
         * removes the first instance of a Song that is in the the UtPod multiple times
             o returns 0 if successful
             o returns -1 if nothing is removed


           input parms -

           output parms -
        */

        int UtPod::removeSong(Song const &s) {
            SongNode *n = songs;
            SongNode *temp;
            while(n != NULL){
                if(n->s == s) {
                    if(n->next == NULL)
                    {
                        delete n;
                        songs = NULL;
                        return SUCCESS;
                    }
                    SongNode *next = n->next;
                    delete n;
                    temp->next = next;
                    return SUCCESS;
                }
                temp = n;
                n = n->next;
            }
            return NOT_FOUND;
        }


        /* FUNCTION - void shuffle
         *  shuffles the songs into random order
            o will do nothing if there are less than two songs in the current list

           input parms -

           output parms -
        */

        void UtPod::shuffle() {
            if (!(songs == NULL || songs->next == NULL))
            {
                int counter = 0;
                SongNode *n = songs;
                while(n != NULL) {
                    counter++;
                    n=n->next;
                }
                for(int i=0;i<2*counter;i++) {
                    int rand1 = (rand() % counter);
                    int rand2 = (rand() % counter);
                    SongNode *swap1;
                    SongNode *swap2;
                    SongNode *n = songs;
                    for(int j=0;j<counter;j++) {
                        if(j == rand1)
                            swap1 = n;
                        if(j == rand2)
                            swap2 = n;
                        n = n->next;
                    }
                    swap(swap1->s,swap2->s);
                }
            }
        }


        /* FUNCTION - void showSongList
         * prints the current list of songs in order from first to last to standard output
         * format - Title, Artist, size in MB (one Song per line)

           input parms -

           output parms -
        */

        void UtPod::showSongList() {
            SongNode *n = songs;
            while(n != NULL)
            {
                cout << n->s.getTitle() << ", " << n->s.getArtist() << ", " << n->s.getSize() << "MB" << endl;
                n = n->next;
            }
        }


        /* FUNCTION - void sortSongList
         *  sorts the songs in ascending order
            o will do nothing if there are less than two songs in the current list

           input parms -

           output parms -
        */

        void UtPod::sortSongList() {
            if (!(songs == NULL || songs->next == NULL)) {

            }
        }


        /* FUNCTION - void clearMemory
         * clears all the songs from memory

           input parms -

           output parms -
        */
        void UtPod::clearMemory() {
            SongNode *n = songs;
            while(n != NULL)
            {
                SongNode *temp = n->next;
                delete n;
                n = temp;
            }
        }

        /* FUNCTION - int getRemainingMemory
         *  returns the amount of memory available for adding new songs

           input parms -

           output parms -
        */

        int UtPod::getRemainingMemory() {
            SongNode *n = songs;
            int total = 0;
            while(n != NULL)
            {
                total += n->s.getSize();
                n = n->next;
            }
            return memSize - total;
        }


        UtPod::~UtPod() {
            clearMemory();
        }

