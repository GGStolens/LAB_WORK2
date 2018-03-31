CC=g++
FLAGS=-c -std=c++14 -Wall -Werror
NAME = lab2
MAIN = main

all: $(NAME)

$(NAME): $(MAIN).o
	$(CC) $(MAIN).o -o $(NAME)

$(MAIN).o: $(MAIN).cpp
	$(CC) $(FLAGS) $(MAIN).cpp

clean:
	rm -rf *.o $(NAME)