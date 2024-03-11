CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
DEPS = FibLFSR.hpp 

.PHONY: all clean

all: PhotoMagic test

PhotoMagic: PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

test: test.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
	
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< 

clean:
	rm *.o PhotoMagic test