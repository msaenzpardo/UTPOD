final: UTPodDriver.o UTPod.o Song.o
	g++ -o UTPod UTPodDriver.o UTPod.o Song.o

UTPodDriver.o: UTPodDriver.cpp UTPod.h Song.h
	g++ -c UTPodDriver.cpp

UTPod.o: UTPod.cpp UTPod.h Song.h
	g++ -c UTPod.cpp

Song.o: Song.cpp Song.cpp
	g++ -c Song.cpp
	