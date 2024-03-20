##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## SDL2 Makefile
##

NAME =  arcade_sdl2.so

SRC = 	Main.cpp

OBJ = $(SRC:.cpp=.o)
CFLAGS = -g -Wall -Wextra -std=c++20 -shared -fPIC

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(CFLAGS) -o $(NAME) $(OBJ)
	mv $(NAME) ../../lib

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../lib/$(NAME)

re: fclean all
