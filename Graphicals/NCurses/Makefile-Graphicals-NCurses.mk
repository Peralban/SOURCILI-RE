##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## NCurses Makefile
##

NAME =  arcade_ncurses.so

SRC = 	NCursesGraphic.cpp

CFLAGS = -g -Wall -Wextra -std=c++20 -shared -fPIC

all: $(NAME)

$(NAME):
	g++ $(CFLAGS) -o $(NAME) $(SRC) -lncurses
	mv $(NAME) ../../lib

fclean:
	rm -f ../../lib/$(NAME)

re: fclean all
