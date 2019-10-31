/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result=t.addSong(s1);
    
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
    t.showSongList(); 

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    t.showSongList();
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << endl;

    t.clearMemory();

    Song dontPlay("Travis Scott", "Don't Play", 4);
    result = t.addSong(dontPlay);
    cout << "add Don't Play result = " << result << endl;

    Song motPatch("Huncho Jack", "Motorcycle Patches", 3);
    result = t.addSong(motPatch);
    cout << "add Motorcycle Patches result = " << result << endl;

    Song darkKnight("Trippie Redd", "Dark Knight Dummo", 4);
    result = t.addSong(darkKnight);
    cout << "add Dark Knight Dummo result = " << result << endl;

    Song dangWorld("Mustard", "Dangerous World", 2);
    result = t.addSong(dangWorld);
    cout << "add Dangerous World result = " << result << endl;

    Song notNet("Travis Scott", "Nothing But Net", 3);
    result = t.addSong(notNet);
    cout << "add Nothing But Net result = " << result << endl;

    Song modSlave("Huncho Jack", "Modern Slavery", 6);
    t.addSong(modSlave);
    cout<<endl;
    t.showSongList();

    Song swerve("A Boogie Wit da Hoodie", "Swervin", 3); 
    result = t.addSong(swerve);
    cout<<"add Swervin result = "<<result<<endl;

    result = t.getSongCount();
    cout<<result<<" songs in pod."<<endl;
    
    t.shuffle();
    t.showSongList();
    cout<<endl;
    t.sortSongList();
    t.showSongList();

    return 0;
}