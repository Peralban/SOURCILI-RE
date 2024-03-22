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

#With this pattern you can just make on other Makefiles by calling the variable and write the rule you want to execute
#Example: $(CORE_MAKEFILE) fclean

CORE_MAKEFILE = make -f Makefile-Core.mk -C Core
GAMES_MAKEFILE = make -f Makefile-Games.mk -C Games
GRAPHICALS_MAKEFILE = make -f Makefile-Graphicals.mk -C Graphicals

all: core games graphicals

core:
	$(CORE_MAKEFILE)

games:
	$(GAMES_MAKEFILE)

graphicals:
	$(GRAPHICALS_MAKEFILE)

clean:
	$(CORE_MAKEFILE) clean

fclean:
	$(CORE_MAKEFILE) fclean
	$(GAMES_MAKEFILE) fclean
	$(GRAPHICALS_MAKEFILE) fclean

core-re: fclean core

games-re: fclean games

graphicals-re: fclean graphicals

re: fclean all

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

tests_run:
	$(CORE_MAKEFILE) tests_run

tests_clean:
	$(CORE_MAKEFILE) tests_clean

