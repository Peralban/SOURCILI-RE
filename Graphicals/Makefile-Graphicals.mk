##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## Graphicals Makefile
##

NCURSES_MAKEFILE = make -f Makefile-Graphicals-NCurses.mk -C NCurses

SDL2_MAKEFILE = make -f Makefile-Graphicals-SDL2.mk -C SDL2

all: ncurses sdl2

ncurses:
	$(NCURSES_MAKEFILE)

sdl2:
	$(SDL2_MAKEFILE)

fclean:
	$(NCURSES_MAKEFILE) fclean
	$(SDL2_MAKEFILE) fclean

re: fclean all
