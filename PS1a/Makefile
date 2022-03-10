CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ = FibLFSR.o test.o
DEPS = FibLFSR.cpp test.cpp
LIBS = -lboost_unit_test_framework
EXE = ps1a

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<
clean: 
	rm $(OBJ) $(EXE)
