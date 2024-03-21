/*
** EPITECH PROJECT, 21/03/24
** testsDLLoader.cpp
** File description:
** DESCRIPTION
*/

#include "include-criterion.hpp"
#include "../../Games/IGame.hpp"

Test(DLLoader, loadGameInstanceOnFunctionnalLib)
{
    DLLoader<IGame> loader("./Tests/LibTests/testsLoadInstance.so");

    std::unique_ptr<IGame> game;
    game.reset(loader.getInstance("loadGameInstance"));
    cr_assert_eq(game->getScore(), 55);
}

Test(DLLoader, loadGameInstance_fail)
{
    try {
        DLLoader<IGame> loader("fail.so");
    } catch (const std::exception &e) {
        cr_assert_str_eq("fail", "fail");
        return;
    }
    cr_assert_fail();
}

Test(DLLoader, loadGameInstance_fail2)
{
    try {
        DLLoader<IGame> loader("libTests/testsLoadInstance.so");
        std::unique_ptr<IGame> game;
        game.reset(loader.getInstance("fail"));
    } catch (const std::exception &e) {
        cr_assert_str_eq("fail", "fail");
        return;
    }
    cr_assert_fail();
}