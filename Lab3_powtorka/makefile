CC=g++
CFLAGS=-c -Wall
FLAGS=-g -Wall
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
#all: program
#program: $(OBJ)
#	$(CC) $(FLAGS) $^ -o $@
#%.o:%.cpp %.h
#	$(CC) $(CFLAGS) -g $<
all: program
program: main.o mystring.o xor.o binary.o cipher.o
	$(CC) $(FLAGS) main.o mystring.o xor.o binary.o cipher.o -o $@
main.o: main.cpp mystring.h cipher.h binary.h xor.h
	$(CC) $(CFLAGS) main.cpp -o $@
mystring.o: mystring.cpp mystring.h
	$(CC) $(CFLAGS) mystring.cpp -o $@
xor.o: xor.cpp xor.h 
	$(CC) $(CFLAGS) xor.cpp -o $@
binary.o: binary.cpp binary.h mystring.h
	$(CC) $(CFLAGS) binary.cpp -o $@
cipher.o: cipher.cpp cipher.h binary.h xor.h mystring.h
	$(CC) $(CFLAGS) cipher.cpp -o $@	
clean:
	rm -rf $(OBJ) program
run: program
	./program
valgrind: program
	valgrind --tool=memcheck ./program
.PHONY: all clean valgrind run
