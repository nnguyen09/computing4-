#C = g++
#CFLAGS = -std=c++11 -I/home/ngan/include -Wall -Werror -pedantic
#OBJ = PhotoMagic.o FibLFSR.o
#DEPS = PhotoMagic.cpp FibLFSR.h FibLFSR.cpp
#LIBS = -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
#EXE = PhotoMagic

all: PhotoMagic

PhotoMagic: PhotoMagic.o FibLFSR.o
	g++ PhotoMagic.o FibLFSR.o -o PhotoMagic -lsfml-graphics -lsfml-window -lsfml-system
PhotoMagic.o: PhotoMagic.cpp FibLFSR.h
	g++ -c PhotoMagic.cpp -I/home/ngan/include -Wall -Werror -pedantic
FibLFSR.o: FibLFSR.cpp FibLFSR.h
	g++ -c FibLFSR.cpp -Wall -Werror -pedantic
clean: 
	rm *.o PhotoMagic