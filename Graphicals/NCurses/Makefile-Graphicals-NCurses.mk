##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## NCurses Makefile
##

NAME =  arcade_ncurses.so

SRC = 	Main.cpp

CFLAGS = -g -Wall -Wextra -std=c++20 -shared -fPIC

all: $(NAME)

$(NAME):
	g++ $(CFLAGS) -o $(NAME) $(SRC)
	mv $(NAME) ../../lib

fclean:
	rm -f ../../lib/$(NAME)

re: fclean all
