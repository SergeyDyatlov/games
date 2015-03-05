CPPFLAGS=-Wall -g
OBJECTS=main.o app.o menuscreen.o
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
main: $(OBJECTS)
	g++ $(OBJECTS) -o game -g -lSDL2
main.o: main.cpp app.h
app.o: app.cpp app.h menuscreen.h
menuscreen.o: menuscreen.cpp menuscreen.h app.h

