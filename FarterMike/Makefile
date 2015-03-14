CPPFLAGS=-Wall -g
OBJECTS=main.o app.o graphicengine.o menuscreen.o button.o spritesheet.o font.o getresourcepath.o level1screen.o
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
main: $(OBJECTS)
	g++ $(OBJECTS) -o game -g -lSDL2 -lSDL2_image
main.o: main.cpp app.h
app.o: app.cpp app.h menuscreen.h level1screen.h graphicengine.h
graphicengine.o: graphicengine.h graphicengine.cpp
spritesheet.o: spritesheet.h spritesheet.cpp
font.o: font.h font.cpp
button.o: button.h button.cpp
menuscreen.o: menuscreen.cpp menuscreen.h app.h spritesheet.h font.h button.h
level1screen.o: level1screen.h level1screen.cpp
getresourcepath.o: getresourcepath.cpp getresourcepath.h
