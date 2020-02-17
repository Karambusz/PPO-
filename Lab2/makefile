CC=g++
CFLAGS=-c -Wall
FLAGS=-g -Wall
SRC=main.cpp
OBJ=$(SRC:.cpp=.o)
all: program
program: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o program
$(OBJ): $(SRC) robots.h
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)
clean:
	rm -rf $(OBJ) program
run: program
	./program
valgrind: program
	valgrind --tool=memcheck ./program
.PHONY: clean all run valgrind
