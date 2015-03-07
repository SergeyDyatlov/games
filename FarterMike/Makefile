CPPFLAGS=-Wall -g
OBJECTS=main.o app.o menuscreen.o img/imgimage.o
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
main: $(OBJECTS)
	g++ $(OBJECTS) -o game -g -lSDL2 -lSDL2_image
main.o: main.cpp app.h
app.o: app.cpp app.h menuscreen.h
IMG_image.o: img/imgimage.h img/imgimage.cpp
menuscreen.o: menuscreen.cpp menuscreen.h app.h img/imgimage.h

