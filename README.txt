Melanie Saenzpardo
mis868
7/19/23

- This program takes a memory implemented by the user or uses a default memory
in order to implement the UTPod. This README file will show you all that the
UTPod has to offer in regards to functions available to the user (public) 

addSong(Song s) 
	The user can add a song to the UTPod through the use of a linked
list. Just please input the title, artist, and memory size of the song you 
would want to add. Please make sure that it doesnt exceed your established 
memory, have blanks, or that your memory is 0. 

removeSong(Song s)
	The user can remove a song from their playlist as long as their 
playlist is not empty. 

shuffle() 
	The user can mix the playlist through their shuffle function as
long as you have more than two songs on the playlist. 

sortSongList() 
	The user can sort their songs in increasingly order in by Artist, Title, and Size as
long as you have more than two songs on the playlist. 

showSongList()
	This prints the playlist everytime there is an operation in order 
to show how the playlist looks like after. It prints in the title, artist, and
size format. 

getTotalMemory()
	Shows the user the total memory that they either established or 
put as default. 

getRemainingMemory()
	Takes into account the total memory of the songs that we have 
in out playlist and subtracts it from total memory in order to let the user know 
how much more memory we have left. 

THINGS TO TAKE INTO CONSIDERATION: 

The Driver will translate the following whenever we try to add or remove a song

Success on either addSong or removeSong = 0 = Success
Failure on addSong = -1 = Fail addSong
Failure on removeSong = -2 = Fail removeSong

Please take this into consideration ^
Also please do not stack overflow since we are using a linked list. 

The code will run the same example with the default and overloaded constructor
and wil test these instances. 

-Add song when size is 0 
-Add song when title or name is blank 
-Add song when the size surpasses available memory 
-Add song when everything is in order 
-Remove song when there is no song to remove 
-Remove song when there is a playlist going on
-Shuffle songs 
-Shuffle songs when we have less than 2 songs
-Sort songs in increasingly order 
-Sort songs when we have less than 2 songs
-Print the playlist
-Translate the outcomes to addSong or removeSong
-Calculates remaining memory
-Calculates total memory
-Can also clear memory (wipe out playlist)

Have fun!!



HOW TO UNZIP: 

-Download the zip file
- Right click on it and click extract 
- Extract it somewhere safe
- Go to Linux and click on the upload arrow in the directory you want it to go
choose the place where you extracted your files and you should be able to see them
- type ls on your command line to make sure that all your files are there

OR 

-Download the zip file 
- put it into your linux directory 
- type in unzip filename.zip 
- then type ls 
- then type make 
- then type ./UTPod
- have fun!!