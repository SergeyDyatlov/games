CPPFLAGS=-Wall -g
OBJECTS=main.o app.o graphicengine.o menuscreen.o font.o getresourcepath.o
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
main: $(OBJECTS)
	g++ $(OBJECTS) -o game -g -lSDL2 -lSDL2_image
main.o: main.cpp app.h
app.o: app.cpp app.h menuscreen.h graphicengine.h
graphicengine.o: graphicengine.h graphicengine.cpp
font.o: font.h font.cpp
menuscreen.o: menuscreen.cpp menuscreen.h app.h sprite.h font.h
getresourcepath.o: getresourcepath.cpp getresourcepath.h
