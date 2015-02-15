CPPFLAGS=-Wall -g
OBJECTS=main.o menustate.o
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
main: $(OBJECTS)
	g++ $(OBJECTS) -o game -g -lGL -lglut
main.o: main.cpp menustate.hpp
menustate.o: menustate.cpp menustate.hpp

