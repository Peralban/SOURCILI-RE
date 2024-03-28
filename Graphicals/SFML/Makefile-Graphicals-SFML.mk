##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## SFML Makefile
##

NAME =  arcade_sfml.so

SRC = 	SFMLGraphic.cpp

CFLAGS = -g -Wall -Wextra -std=c++20 -shared -fPIC -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME):
	g++ $(CFLAGS) -o $(NAME) $(SRC)
	mv $(NAME) ../../lib

fclean:
	rm -f ../../lib/$(NAME)

re: fclean all
