/* UTPod_driver.cpp
Demo Driver for the UTPod.

Roger Priebe
EE 312 10/16/18


Melanie Saenzpardo
This is a basic driver for the UTPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UTPod.h"

using namespace std;

void createDisplay (UTPod& t) {
    cout << "---------------" << endl;
    t.showSongList();
    cout << "---------------" << endl;
}

void translate (int res) {
    if (res == 0) {
        cout << "Success" << endl;
    }

    if (res == -1) {
        cout << "Failed addSong" << endl;
    }

    if (res == -2) {
        cout << "Failed removeSong" << endl;
    }
}
int main(int argc, char *argv[])
{
    /*
     * First test the overloaded constructor
     */
    UTPod t(500);

    //UTPod t(300);

    cout << "Loading UTPod Object with Overloaded Constructor..." << endl;

    /*
     * Add songs case
     */
    Song s1("Harry Styles", "Satellite", 50);
    int result = t.addSong(s1);
    translate(result);
    //cout << "addSong Result = " << result << endl;
    createDisplay(t);

    /*
     * the following 3 are the failed test cases, I tried to add songs when the strings are blank, when the
     * size is zero, and when the memory of the song is more than the maximum size
     */
    Song sf("", "", 5);
    result = t.addSong(sf);
    translate(result);
    //cout << "addSong Result = " << result << endl;
    createDisplay(t);

    Song sf2("Beyonce", "Halo", 0);
    result = t.addSong(sf2);
    translate(result);
    //cout << "addSong Result = " << result << endl;
    createDisplay(t);

    Song sf3("Beyonce", "Upgrade U", 510);
    result = t.addSong(sf3);
    translate(result);
    //cout << "addSong Result = " << result << endl;
    createDisplay(t);

    /*
     * add more songs
     */
    Song s2("Kali Uchis", "Moonlight", 5);
    result = t.addSong(s2);
    translate(result);
    //cout << "addSong Result = " << result << endl;
    createDisplay(t);

    Song s3("Tyler, The Creator", "SORRY NOT SORRY", 6);
    result = t.addSong(s3);
    translate(result);
    //cout << "addSong Result = " << result << endl;
    createDisplay(t);

    Song s4("Kali Uchis", "After the Storm", 7);
    result = t.addSong(s4);
    cout << "addSong Result = " << result << endl;
    createDisplay(t);

    Song s5("Frank Ocean", "Ivy", 241);
    result = t.addSong(s5);
    translate(result);
    //cout << "addSong Result = " << result << endl;
    createDisplay(t);

    /*
     * shuffle the playlist
     */
    cout << "Shuffling your playlist..." << endl;
    t.shuffle();
    cout << "Done!" << endl;
    createDisplay(t);

    /*
     * sort the songs
     */
    cout << "Sorting songs (by title, then artist, then size)..." << endl;
    t.sortSongList();
    cout << "Done!" << endl;
    createDisplay(t);

    cout << "Removing songs..." << endl;

    /*
     * test out the removal of songs
     */
    result = t.removeSong(s3);
    translate(result);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(t);

    result = t.removeSong(s4);
    translate(result);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(t);

    result = t.removeSong(s5);
    translate(result);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(t);

    result = t.removeSong(s2);
    translate(result);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(t);

    result = t.removeSong(s1);
    translate(result);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(t);

    /*
     * try to remove the song that already has been removed.
     */
    result = t.removeSong(s1);
    translate(result);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(t);

    cout << "Total Memory: " << t.getTotalMemory() << " MB" << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << " MB" << endl;

    /*
     * try to implement a song that has more memory than maximum
     */
    Song s7("SZA", "Open Arms", 512);
    result = t.addSong(s7);
    translate(result);
    //cout << "addSong Result = " << result << endl;
    createDisplay(t);

    /*
     * add this song (should only be one) to show that there is no songs to sort or shuffle around
     */
    Song s8("Harry Styles", "Satellite", 50);
    result = t.addSong(s1);
    translate(result);
    //cout << "addSong Result = " << result << endl;
    createDisplay(t);

    t.sortSongList();
    createDisplay(t);

    t.shuffle();
    createDisplay(t);

    // get total memory and the remaining memory
    cout << "Total Memory: " << t.getTotalMemory() << " MB" << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << " MB" << endl;
    createDisplay(t);

    /*
     * free the memory
     */
    cout << "Freeing memory..." << endl;
    t.clearMemory();
    createDisplay(t);

    cout << "Total Memory: " << t.getTotalMemory() << " MB" << endl;
    cout << "Remaining Memory: " << t.getRemainingMemory() << " MB" << endl;

    cout << "---------------" << endl;
    cout << "Goodbye!" << endl;
    cout << "\n";

    // NEW ONE TEST BOTH

    /*
    * test the default constructor
    */
    UTPod m;

    //UTPod t(300);

    cout << "Loading UTPod Object with Default Constructor..." << endl;

    /*
     * Add songs case
     */
    Song m1("Harry Styles", "Satellite", 50);
    int res = m.addSong(s1);
    translate(res);
    //cout << "addSong Result = " << result << endl;
    createDisplay(m);

    /*
     * the following 3 are the failed test cases, I tried to add songs when the strings are blank, when the
     * size is zero, and when the memory of the song is more than the maximum size
     */
    Song mf("", "", 5);
    res = m.addSong(mf);
    translate(res);
    //cout << "addSong Result = " << result << endl;
    createDisplay(m);

    Song mf2("Beyonce", "Halo", 0);
    res = m.addSong(mf2);
    translate(res);
    //cout << "addSong Result = " << result << endl;
    createDisplay(m);

    Song mf3("Beyonce", "Upgrade U", 510);
    res = m.addSong(mf3);
    translate(res);
    //cout << "addSong Result = " << result << endl;
    createDisplay(m);

    /*
     * add more songs
     */
    Song m2("Kali Uchis", "Moonlight", 5);
    res = m.addSong(m2);
    translate(res);
    //cout << "addSong Result = " << result << endl;
    createDisplay(m);

    Song m3("Tyler, The Creator", "SORRY NOT SORRY", 6);
    res = m.addSong(m3);
    translate(res);
    //cout << "addSong Result = " << result << endl;
    createDisplay(m);

    Song m4("Kali Uchis", "After the Storm", 7);
    res = m.addSong(m4);
    cout << "addSong Result = " << res << endl;
    createDisplay(m);

    Song m5("Frank Ocean", "Ivy", 241);
    res = m.addSong(m5);
    translate(res);
    //cout << "addSong Result = " << result << endl;
    createDisplay(m);

    /*
     * shuffle the playlist
     */
    cout << "Shuffling your playlist..." << endl;
    m.shuffle();
    cout << "Done!" << endl;
    createDisplay(m);

    /*
     * sort the songs
     */
    cout << "Sorting songs (by title, then artist, then size)..." << endl;
    m.sortSongList();
    cout << "Done!" << endl;
    createDisplay(m);

    cout << "Removing songs..." << endl;

    /*
     * test out the removal of songs
     */
    res = m.removeSong(m3);
    translate(res);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(m);

    res = m.removeSong(m4);
    translate(res);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(m);

    res = m.removeSong(m5);
    translate(res);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(m);

    res = m.removeSong(m2);
    translate(res);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(m);

    res = m.removeSong(m1);
    translate(res);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(m);

    /*
     * try to remove the song that already has been removed.
     */
    res = m.removeSong(m1);
    translate(res);
    //cout << "removeSong Result: " << result <<  endl;
    createDisplay(m);

    cout << "Total Memory: " << m.getTotalMemory() << " MB" << endl;
    cout << "Remaining Memory: " << m.getRemainingMemory() << " MB" << endl;

    /*
     * try to implement a song that has more memory than maximum
     */
    Song m7("SZA", "Open Arms", 512);
    res = m.addSong(m7);
    translate(res);
    //cout << "addSong Result = " << result << endl;
    createDisplay(m);

    /*
     * add this song (should only be one) to show that there is no songs to sort or shuffle around
     */
    Song m8("Harry Styles", "Satellite", 50);
    res = m.addSong(m8);
    translate(res);
    //cout << "addSong Result = " << result << endl;
    createDisplay(m);

    m.sortSongList();
    createDisplay(m);

    m.shuffle();
    createDisplay(m);

    // get total memory and the remaining memory
    cout << "Total Memory: " << m.getTotalMemory() << " MB" << endl;
    cout << "Remaining Memory: " << m.getRemainingMemory() << " MB" << endl;
    createDisplay(m);

    /*
     * free the memory
     */
    cout << "Freeing memory..." << endl;
    m.clearMemory();
    createDisplay(m);

    cout << "Total Memory: " << m.getTotalMemory() << " MB" << endl;
    cout << "Remaining Memory: " << m.getRemainingMemory() << " MB" << endl;

    cout << "---------------" << endl;
    cout << "Goodbye!" << endl;

}
