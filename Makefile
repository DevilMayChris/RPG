CFLAGS=-g

simple-rpg: main.cpp object.o moving_object.o monster.o player.o
	g++ ${CFLAGS} main.cpp player.o monster.o moving_object.o object.o -o simple-rpg

player.o: object.h moving_object.h player.h player.cpp
	g++ ${CFLAGS} -c player.cpp

monster.o: object.h moving_object.h monster.h monster.cpp
	g++ ${CFLAGS} -c monster.cpp

moving_object.o: object.h moving_object.h moving_object.cpp
	g++ ${CFLAGS} -c moving_object.cpp

object.o: object.h object.cpp
	g++ ${CFLAGS} -c object.cpp

.PHONY: clean 
clean: 
	rm -f *.o simple-rpg

.PHONY: 
doc: main.cpp object.h object.cpp moving_object.h moving_object.cpp monster.h monster.cpp player.h player.cpp
	doxygen

install: simple-rpg
	cp simple-rpg /usr/bin/
	cp simple-rpg.6 /usr/share/man/man6/
	[ -d /usr/share/doc/simple-rpg ] || mkdir -p /usr/share/doc/simple-rpg
	cp LICENSE /usr/share/doc/simple-rpg

.PHONY: uninstall
uninstall: 
	rm /usr/bin/simple-rpg
	rm /usr/share/man/man6/simple-rpg.6
	rm -rf /usr/share/doc/simple-rpg
