##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## Games Makefile
##

SNAKE_MAKEFILE = make -f Makefile-Games-Snake.mk -C Snake

all: snake

snake:
	$(SNAKE_MAKEFILE)

fclean:
	$(SNAKE_MAKEFILE) fclean

re: fclean all
