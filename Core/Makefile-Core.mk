##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## Core Makefile
##

NAME =  arcade

SRC = 	Main.cpp	\
		Core.cpp	\

OBJ = $(SRC:.cpp=.o)
CFLAGS = -g -Wall -Wextra -std=c++20

TESTS_SRC = 	Tests/TestsDLLoader.cpp

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

tests_run:
	make -f Makefile-Tests-DLLoader.mk -C Tests/LibTests/
	echo -e "\033[0;32m Compiling of core tests \033[0m"
	g++ -o tests $(TESTS_SRC) --coverage -lcriterion
	echo -e "\033[0;32m Executing core tests \033[0m"
	./tests
	make -f Makefile-Tests-DLLoader.mk -C Tests/LibTests/ fclean

tests_clean:
	echo -e "\033[0;32m Deleting core tests \033[0m"
	rm -f tests*