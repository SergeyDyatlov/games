CPPFLAGS=-Wall -g
OBJECTS=main.o menustate.o gamestatemanager.o
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
main: $(OBJECTS)
	g++ $(OBJECTS) -o game -g -lGL -lglut
main.o: main.cpp gamestatemanager.hpp
menustate.o: menustate.cpp menustate.hpp
gamestatemanager.o: gamestatemanager.hpp gamestatemanager.cpp

