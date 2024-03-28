/*
** EPITECH PROJECT, 26/03/24
** Core.cpp
** File description:
** DESCRIPTION
*/

#include "Core.hpp"
#include "DLLoader.hpp"
#include <filesystem>

Arcade::Core::Core(std::string pathToLib) : _currentGameIndex(0), _currentGraphicalIndex(0), _score(0)
{
    _IsRun = true;
    try {
        BuildLibVectors(pathToLib);
        SetGraphical(pathToLib);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(84);
    }
}

void Arcade::Core::BuildLibVectors(std::string pathToLib) {
    _graphicals.clear();
    _games.clear();
    if (!std::filesystem::exists("./lib"))
        throw LibNotFound();
    DLLoader<Arcade::IGraphic> loader(pathToLib);
    if (loader.getInstance("loadGraphicInstance") == nullptr)
        throw EntryNotFound();
    _graphicals.push_back(pathToLib);
    for (const auto &entry : std::filesystem::directory_iterator("./lib")) {
        if (entry.path().extension() == ".so" && pathToLib.find(entry.path().filename()) == std::string::npos) {
            DLLoader<Arcade::IGraphic> loader(entry.path());
            if (loader.getInstance("loadGraphicInstance") != nullptr) {
                _graphicals.push_back(entry.path());
            } else if (loader.getInstance("loadGameInstance") != nullptr) {
                _games.push_back(entry.path());
            } else {
                throw LibType();
            }
        }
    }
}

void Arcade::Core::SetGraphical(std::string pathToLib)
{
    try {
        Arcade::DLLoader<Arcade::IGraphic> loader(pathToLib);
        _currentGraphic.reset(loader.getInstance("loadGraphicInstance"));
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(84);
    }
}

void Arcade::Core::LoadPreviousGraphical()
{
    _currentGraphicalIndex -= 1;
    if (_currentGraphicalIndex < 0)
        _currentGraphicalIndex = _graphicals.size() - 1;
    try {
        Arcade::DLLoader<Arcade::IGraphic> loader(_graphicals[_currentGraphicalIndex]);
        _currentGraphic.reset(loader.getInstance("loadGraphicInstance"));
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Arcade::Core::LoadNextGraphical()
{
    _currentGraphicalIndex += 1;
    _currentGraphicalIndex %= _graphicals.size();
    try {
        Arcade::DLLoader<Arcade::IGraphic> loader(_graphicals[_currentGraphicalIndex]);
        _currentGraphic.reset(loader.getInstance("loadGraphicInstance"));
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Arcade::Core::LoadPreviousGame()
{
    _currentGameIndex -= 1;
    if (_currentGameIndex < 0)
        _currentGameIndex = _games.size() - 1;
    try {
        Arcade::DLLoader<Arcade::IGame> loader(_games[_currentGameIndex]);
        _currentGame.reset(loader.getInstance("loadGameInstance"));
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        LoadNextGame();
    }
}

void Arcade::Core::LoadCurrentGame()
{
    try {
        Arcade::DLLoader<Arcade::IGame> loader(_games[_currentGameIndex]);
        _currentGame.reset(loader.getInstance("loadGameInstance"));
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        LoadNextGame();
    }
}

void Arcade::Core::LoadNextGame()
{
    _currentGameIndex += 1;
    _currentGameIndex %= _games.size();
    try {
        Arcade::DLLoader<Arcade::IGame> loader(_games[_currentGameIndex]);
        _currentGame.reset(loader.getInstance("loadGameInstance"));
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        LoadPreviousGame();
    }
}

void Arcade::Core::GameToMenu(bool stopGame)
{
    if (stopGame)
        _currentGame->stopGame();
    _currentGame.reset(_menu.get());
    _currentGame->startGame();
}

void Arcade::Core::MenuToGame()
{
    _currentGame->stopGame();
    LoadCurrentGame();
    _currentGame->startGame();
}

void Arcade::Core::RestartGame()
{
    _currentGame->stopGame();
    _currentGame->startGame();
}

void Arcade::Core::DisplayAndPlay()
{
    _currentGraphic->clearWindow();
    _currentGraphic->displayEntities(_currentGame->getEntities());
    _currentGraphic->displayText(_currentGame->getTexts());
    _currentGraphic->playSound(_currentGame->getSounds());
    _currentGraphic->displayWindow();
}

void Arcade::Core::ManageRestart()
{
    if (_currentGame.get() != _menu.get()) { // Restart the game if it's not the menu
        RestartGame();
    } else { // Start the game if it's the menu
        MenuToGame();
    }
}

void Arcade::Core::ManageKeyEvent()
{
    _keyEvent = (Arcade::Keys) _currentGraphic->getKeyEvent();
}

void Arcade::Core::SendKeyEvent()
{
    _currentGame->catchKeyEvent(_keyEvent);
}

void Arcade::Core::execArcade()
{
    std::cout << "passing 3" << std::endl;
    //GameToMenu();
    LoadCurrentGame();
    std::cout << "pointer: " << _currentGame.get() << std::endl;
    _currentGame->startGame();
    std::cout << "passing 4" << std::endl;
    std::cout << "pointer Graphic: " << _currentGraphic.get() << "Is Run: " << _IsRun << std::endl;
    while (_currentGraphic->isWindowOpen() && _IsRun) {
        std::cout << "passing 5" << std::endl;
        if (_currentGame->simulate() == 1)
            break;
        std::cout << "passing 6" << std::endl;
        DisplayAndPlay();
        _score = _currentGame->getScore();
        ManageKeyEvent();
        std::cout << "passing 7" << std::endl;
        if (_keyMap.find(_keyEvent) != _keyMap.end())
            _keyMap[_keyEvent]();
        else
            SendKeyEvent();
    }
    _currentGame->stopGame();
    _currentGraphic->closeWindow();
}