##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## Snake Makefile
##

NAME =  testsLoadInstance.so

SRC = 	testsLoadInstance.cpp

OBJ = $(SRC:.cpp=.o)
CFLAGS = -g -Wall -Wextra -std=c++20 -shared -fPIC

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
