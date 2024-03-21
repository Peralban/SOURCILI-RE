##
## EPITECH PROJECT, 2024
## ARCADE
## File description:
## Makefile
##

ALL_INTERFACES = Games/IEntity.hpp 			\
				 Games/IGame.hpp 			\
				 Graphicals/IGraphic.hpp 	\
				 Graphicals/ISound.hpp 		\
				 Graphicals/IText.hpp 		\

SUBMODULES_GAMES_INTERFACES = Shared-Arcade/Interfaces/IEntity.hpp 	\
							  Shared-Arcade/Interfaces/IGame.hpp 	\

SUBMODULES_GRAPHICALS_INTERFACES = Shared-Arcade/Interfaces/IGraphic.hpp 	\
								   Shared-Arcade/Interfaces/ISound.hpp 		\
								   Shared-Arcade/Interfaces/IText.hpp 		\

GAMES_PATH = Games/

GRAPHICALS_PATH = Graphicals/

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

re: fclean all tests_clean

update-submodules:
	@git submodule update --init --recursive
	@git submodule update --remote --merge
	@rm -f $(ALL_INTERFACES)
	@cp $(SUBMODULES_GAMES_INTERFACES) $(GAMES_PATH)
	@cp $(SUBMODULES_GRAPHICALS_INTERFACES) $(GRAPHICALS_PATH)
	@echo -e "\033[0;32mSubmodules updated in their respective folders ✅\033[0m"

check-submodules:
	@if git submodule status | grep -q '^+' ; then \
		echo -e "\033[0;31mSubmodule not up to date ❌\033[0m" ; \
		exit 1 ; \
	fi
	@echo -e "\033[0;32mSubmodule up to date ✅\033[0m"

check-interfaces:
	@if diff $(GAMES_PATH)IEntity.hpp Shared-Arcade/Interfaces/IEntity.hpp && \
		diff $(GAMES_PATH)IGame.hpp Shared-Arcade/Interfaces/IGame.hpp && \
		diff $(GRAPHICALS_PATH)IGraphic.hpp Shared-Arcade/Interfaces/IGraphic.hpp && \
		diff $(GRAPHICALS_PATH)ISound.hpp Shared-Arcade/Interfaces/ISound.hpp && \
		diff $(GRAPHICALS_PATH)IText.hpp Shared-Arcade/Interfaces/IText.hpp ; then \
		echo -e "\033[0;32mInterfaces are identical to those in Shared-Arcade/Interfaces ✅\033[0m" ; \
	else \
		echo -e "\033[0;31mInterfaces are not identical to those in Shared-Arcade/Interfaces ❌\033[0m" ; \
		exit 1 ; \
	fi

tests_run:
	make -C Core tests_run

tests_clean:
	make -C Core tests_clean