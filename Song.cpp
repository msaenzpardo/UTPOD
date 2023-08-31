//
// Created by melan on 7/15/2023.
//
#include <iostream>
#include <string>
#include "Song.h"


Song::Song() {
songArtist = "noArtistName";
songName = "noSongName";
songSize = -1;
}

Song::Song(string const artist, string const name, int size) {
    songName = name;
    songArtist = artist;
    songSize = size;
}

/*
 * getter functions work in order to access the private functions. just return them and make sure you add const as a
 * way to prevent the variables from being edited.
 */
string Song::getTitle() const{
    return songName;
}

string Song::getArtist() const{
    return songArtist;
}

int Song::getSize() const {
    return songSize;
}

/*
 * setter functions just set the private variables. Just make sure you equal the private variables to the
 * parameters that we are getting from the user
 */
void Song::setTitle(string song_Title) {
    songName = song_Title;
}

void Song::setArtist(string song_Artist){
    songArtist = song_Artist;
}

void Song::setSize(int song_Size) {
    songSize = song_Size;
}

/*
 * So if we think about it, a song will be equal to another song it if
 * has: same title, same artist, and same size.
 * So, the function will be true when the statements made above are true!
 */
bool Song::operator ==(Song const &rhs) {
    if ((songName == rhs.songName) && (songArtist == rhs.songArtist) && (songSize == rhs.songSize)) {
        return true;
    }

    return false;
}

/*
 * So for the following boolean operators we need to compare by doing artist, then title, then size.
 */
bool Song:: operator <(Song const  &rhs) {
    /*
     * Check artist
     */
    if (songArtist < rhs.songArtist) {
        return true;
    }
    /*
     * Now we will check when the artist is equal: the title or size might be
     * different
     */
    else if (songArtist == rhs.songArtist){
        if (songName < rhs.songName) {
            return true;
        }
        else if (songName == rhs.songName) {
            if (songSize < rhs.songSize) {
                return true;
            }
        }
    }
    return false;
}

/*
 * think about this.
 */
/*bool Song::operator > (Song const &rhs) {
    return true;
} */