/*
** EPITECH PROJECT, 26/03/24
** Core.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <functional>

#include "../Games/IGame.hpp"
#include "../Graphicals/IGraphic.hpp"
#include "../Games/Keys.hpp"

namespace Arcade {

    class Core {
    public:
        class CoreException : public std::exception {
        public:
            CoreException(const std::string message) : _message(message) {}
            const char *what() const noexcept override { return _message.c_str(); }
        private:
            std::string _message;
        };

        class GameNotFound : public CoreException {
        public:
            GameNotFound() : CoreException("Game not found") {}
        };

        class GraphicalNotFound : public CoreException {
        public:
            GraphicalNotFound() : CoreException("Graphical not found") {}
        };

        class LibNotFound : public CoreException {
        public:
            LibNotFound() : CoreException("Lib not found") {}
        };

        class LibType : public CoreException {
        public:
            LibType() : CoreException("Invalid type") {}
        };

        class EntryNotFound : public CoreException {
        public:
            EntryNotFound() : CoreException("Entry not found") {}
        };

        Core(std::string pathToLib);
        ~Core() = default;

        // Load Lib
        void SetGraphical(std::string pathToLib);
        void BuildLibVectors(std::string pathToLib);
        void LoadPreviousGraphical();
        void LoadNextGraphical();
        void LoadPreviousGame();
        void LoadCurrentGame();
        void LoadNextGame();

        //Core Function
        void execArcade();
        void EndRun() { _IsRun = false; }

        //Manage Game and menu
        void ManageRestart();
        void GameToMenu(bool restart = false);
        void MenuToGame();
        void RestartGame();

        //Core Event
        void DisplayAndPlay();

        // Manage Key Event
        void ManageKeyEvent();
        void SendKeyEvent();


    private:
        std::unique_ptr<Arcade::IGame> _menu;
        std::unique_ptr<Arcade::IGame> _currentGame;
        std::unique_ptr<Arcade::IGraphic> _currentGraphic;
        size_t _currentGameIndex;
        size_t _currentGraphicalIndex;
        int _score;
        std::string _name;
        Arcade::Keys _keyEvent;
        std::vector<std::string> _graphicals;
        std::vector<std::string> _games;
        bool _IsRun;

        // Map to manage key event
        std::unordered_map<Arcade::Keys, std::function<void()>> _keyMap = {
            {Arcade::Keys::BACKSPACE, std::bind(&Core::GameToMenu, this, false)},
            {Arcade::Keys::ESCAPE, std::bind(&Core::execArcade, this)},
            {Arcade::Keys::ENTER, std::bind(&Core::ManageRestart, this)},
            {Arcade::Keys::D, std::bind(&Core::LoadNextGame, this)},
            {Arcade::Keys::Q, std::bind(&Core::LoadPreviousGame, this)},
            {Arcade::Keys::C, std::bind(&Core::LoadNextGraphical, this)},
            {Arcade::Keys::W, std::bind(&Core::LoadPreviousGraphical, this)}
        };
    };
}