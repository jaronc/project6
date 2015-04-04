all: slots

slots: main.cpp str.o reel.o symbol.o
	g++ main.cpp str.o symbol.o reel.o -o slots

str.o: str.cpp
	g++ -c str.cpp

symbol.o: symbol.cpp
	g++ -c symbol.cpp

reel.o: reel.cpp
	g++ -c reel.cpp

clean: rm -rf *.o slots
