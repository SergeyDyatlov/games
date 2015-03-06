CPPFLAGS=-Wall -g
OBJECTS=main.o app.o menuscreen.o IMG_image.o
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
main: $(OBJECTS)
	g++ $(OBJECTS) -o game -g -lSDL2 -lSDL2_image
main.o: main.cpp app.h
app.o: app.cpp app.h menuscreen.h
IMG_image.o: IMG_image.h IMG_image.cpp
menuscreen.o: menuscreen.cpp menuscreen.h app.h IMG_image.h

