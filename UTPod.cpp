//
// Created by melan on 7/15/2023.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include "UTPod.h"
#include "Song.h"

using namespace std;

//Default constructor
//set the memory size to MAX_MEMORY
UTPod::UTPod(){
 memSize = MAX_MEMORY;
 /*
  * We will also initialize the linked list. Since we are initializing it
  * we will make the head pointer (songs) point to the null so that
  * way we know that it's not really pointing to anything (the tail)
  */
 songs = NULL;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UTPod::UTPod(int size) {
    if ((size <= 0) || (size > MAX_MEMORY)) {
        size = MAX_MEMORY;
    }

    memSize = size;
    /*
     * The point of the constructor changes only by a little bit (now
     * including the size as a parameter) but we will still keep the songs
     * pointer point to the NULL as a way to initialize the linked list.
     */
    songs = NULL;
}

/* FUNCTION - int addSong
     * attempts to add a new song to the UTPod
         o returns a 0 if successful
         o returns -1 if not enough memory to add the song

     precondition: s is a valid Song

     input parms - Song s

     output parms - no memory (-1) or success (0)
    */
int UTPod :: addSong(Song const &s) {
    if ((s.getArtist() == "") || (s.getTitle() == "") || (s.getSize() > getRemainingMemory()) || (s.getSize()) == 0) {
        cout << "---------------" << endl;
        return NO_MEMORY;
    }
    /*
     * If the size that we currently for the song that we are about to input is bigger than the remaining
     * memory then we will return a statement saying that there is no memory available
     */

    /*
     * Otherwise, the way that the addSong function will work is that we will be pre-pending elements to the linked
     * list as a way to add the songs (since we dont have a tail).
     */
    SongNode *addToSong = new SongNode;
    addToSong -> s = s;
    //cout << addToSong->s.getArtist();
    addToSong -> next = NULL;

    /*
     * if the songs is NULL then we will just make the head point to the first element in the linked list
     */
    if (songs == NULL) {
        songs = addToSong;
    }

    /*
     * otherwise, we will start by prepending the linked list.
     */
    else {
        addToSong -> next = songs;
        songs = addToSong;
        //SongNode *test = addToSong->next;
        //cout << test->s.getTitle();
    }
    /*
     * return success
     */
    cout << "---------------" << endl;
    return SUCCESS;
}

/* FUNCTION - int removeSong
     * attempts to remove a song from the UTPod
     * removes the first instance of a song that is in the UTPod multiple times
         o returns 0 if successful
         o returns -2 if nothing is removed


       input parms - Song s

       output parms - succes (0) or not found (-2)
    */
int UTPod:: removeSong(Song const &s) {
    /*
     * in order to perform removeSong we will have to take in the previous node (as a temporary variable) and the
     * current node. We will make the previous node point to the next in the current node.
     */
    SongNode *curr = songs;
    SongNode *prev = NULL;

    while (songs != NULL) {
        if (curr->s == s) {
            if (prev != NULL) {
                //SongNode *temp = curr -> next;
                //cout << curr->s.getArtist();
                prev -> next = curr -> next;
            }

            else {
                songs = curr -> next;
            }
            //cout << curr->s.getArtist();
            /*
             * since we allocated memory in the addSong function then we will also need to deallocate the memory
             * by deleting the current node (or the node that we are trying to get rid of) .
             */
            delete (curr);
            cout << "---------------" << endl;
            return SUCCESS;
        }
        /*
         * then the previous node becomes the current node and the curr node is the next node that we were supposed
         * to point to
         */
        prev = curr;
        curr = curr -> next;
    }
    cout << "---------------" << endl;
    return NOT_FOUND;
}

/* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms - nothing

       output parms - shuffles the songs or outputs not enough nodes to shuffle if there is less than two songs
    */
// check the null pointer

void UTPod:: shuffle() {
    /* if the linked list is empty or if the next item pointing from the head is
     * null (meaning that there is only one node in total)
     */
    if ((songs == NULL) || (songs -> next == NULL)) {
        cout << "Not enough nodes to shuffle" << endl;
      return;
    }

    int listLen = 0;
    SongNode *curr = songs;
    while (curr != NULL) {
        listLen++;
        curr = curr -> next;
    }

    /*
     * we will use fisher yates algorithm in order to shuffle the list of songs.
     */
    for (int i = 0; i < listLen -1; i++) {
        int j = i + rand() % (listLen - 1);
        curr = songs;
        for (int m = 0; m < i; m++) {
            curr = curr -> next;
            if (curr == NULL) {
                return;
            }
        }
        SongNode *currNode = curr;
        for (int h = i; h < j; h++) {
            curr = curr -> next;
            if (curr == NULL) {
                return;
            }
        }

        SongNode *nextNode = curr;
        swap(currNode -> s, nextNode -> s);
        //for (int n)
    }
    //cout << "Number of nodes:" << listLen << endl;
}

/* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)

       input parms - nothing

       output parms - formats the songs by artist, title, and size
    */
void UTPod::showSongList() {
    SongNode *printThis = songs;

    if (printThis == NULL) {
        cout << "No Songs Found" << endl;
        return;
    }
    else {
        /*
         * Print out the artist, title, and then the size followed by the MB's
         */
        while (printThis != NULL) {
            cout << printThis->s.getTitle() << "-" << printThis->s.getArtist() << ", " << printThis->s.getSize() << " MB"
                 << endl;
            printThis = printThis->next;
        }
    }
}

/* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
        o will do nothing if there are less than two songs in the current list

       input parms -nothing

       output parms - sorts the songs by artist, title, and song
    */
void UTPod::sortSongList() {
    if (songs == NULL || songs -> next == NULL) {
        cout << "Not enough nodes to sort" << endl;
        return;
    }

    /*
     * first get the number of nodes in the linked list in order to know how many iterations we will need
     * to perform in order to do bubble sort.
     */
    int listLen = 0;
    SongNode *temp = songs;
    while (temp != NULL) {
        listLen++;
        temp = temp -> next;
    }

    /*
     * bubble sort wil be performed
     */
    int i,j;
    bool swapped;
    for (i = 0; i < (listLen -1); i++) {
        SongNode *curr = songs; // node1
        SongNode *prev = NULL; // node 2
        //SongNode* smallInt = NULL;
        swapped = false;
        for (j = 0; j < (listLen - i - 1); j++) {
            prev = curr;
            curr = curr->next;
            /*
             * go through the iterations by comparing the previous and the current node. If the current node is smaller
             * than the previous node then we will swap them.
             */
            if (curr->s < prev->s) {
                // Swap function. Make a temporary variable in order to swap the information.
                Song storage;
                storage = curr->s;
                curr->s = prev->s;
                prev->s = storage;
                swapped = true;
            }
            /*
             * return if we keep making no swaps (false)
             */
        }
        if (swapped == 0) {
            return;
        }
    }

}

/* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms - nothing

       output parms - frees nodes
    */
void UTPod::clearMemory() {
    SongNode* curr = songs;
    SongNode* next = NULL;

    /*
     * we will basically deallocate every node until we get to the part where the node points to the NULL terminator
     */
    while (curr != NULL) {
        next = curr -> next;
        delete(curr);
        curr = next;
    }
    songs = NULL;
}

/* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

       input parms -

       output parms -
    */
int UTPod::getRemainingMemory() {
    /*
     * count the number of memory used by iterating through the nodes and then adding it. Subtract from the total
     * memory and then return the value that it gives you.
     */
    int memUsed = 0;
    SongNode *test = songs;
    while (test != NULL) {
        memUsed += test->s.getSize();
        test = test->next;
    }
    return (getTotalMemory()-memUsed);
}

/*
 * deconstructor.
 */
UTPod :: ~UTPod() {
    clearMemory();
}