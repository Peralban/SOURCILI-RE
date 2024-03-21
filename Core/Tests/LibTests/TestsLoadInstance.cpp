/*
** EPITECH PROJECT, 21/03/24
** entrypointSnake.cpp
** File description:
** DESCRIPTION
*/

#include "TestsLoadInstance.hpp"

extern "C"
{
    IGame *loadGameInstance()
    {
        return new TestsGame();
    }
}