##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## Core Makefile
##

NAME =  arcade

SRC = 	Main.cpp

OBJ = $(SRC:.cpp=.o)
CFLAGS = -g -Wall -Wextra -std=c++20

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all
