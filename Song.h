//
// Created by melan on 7/15/2023.
//

/*#ifndef ECE312_PROJECT5_SONG_H
#define ECE312_PROJECT5_SONG_H

#endif //ECE312_PROJECT5_SONG_H*/

#ifndef Song_H
#define Song_H

#include <iostream>
#include <string>

using namespace std;

class Song {
private:
    string songArtist;
    string songName;
    int songSize;
public:
    /*
     * Default constructor
     */
    Song();
    /*
     * Constructor where the title, artist, and size will be passed by
     * the user
     */
    Song(string const artist, string const name, int size );

    /*
     * Now we will start with the getter functions for the
     * title, artist, and size.
     * As a reminder
     */

    // ** look on whether we need to implement the const.
    string getTitle() const;

    string getArtist() const;

    int getSize() const;

    /*
     * Then we also have to implement the setter functions for the
     * title, artist, and size of the song.
     */

    void setTitle(string song_Title);

    void setArtist(string song_Artist);

    void setSize(int song_Size);

    /*
     * Overload boolean operators. As said in pdf we must overload ==, <, and >
     * or any other operators that we think we will need.
     * These will come in handy for when we have to compare in between two songs.
     */

    bool operator ==(Song const &rhs);

    bool operator <(Song const &rhs);

};

#endif //Song_H