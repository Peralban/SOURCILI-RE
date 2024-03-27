/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Main.cpp
*/

#include <iostream>
#include "DLLoader.hpp"
#include "Core.hpp"

static std::string CheckArgs(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " [path_to_graphical_library.so]" << std::endl;
        exit(84);
    }
    return av[1];
}

int main(int ac, char **av)
{
    std::string pathToGraphLib = CheckArgs(ac, av);
    Arcade::Core core(pathToGraphLib);
    std::cout << "Core created" << std::endl;
    core.execArcade();
    return 0;
}
