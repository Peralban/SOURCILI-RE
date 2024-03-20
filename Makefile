##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## Makefile
##

all: core games graphicals

core:
	make -C Core

games:
	make -C Games

graphicals:
	make -C Graphicals

clean:
	make -C Core clean
	make -C Games clean
	make -C Graphicals clean

fclean:
	make -C Core fclean
	make -C Games fclean
	make -C Graphicals fclean

core-re: fclean core

games-re: fclean games

graphicals-re: fclean graphicals

re: fclean all
