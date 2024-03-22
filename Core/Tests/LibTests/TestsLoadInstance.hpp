/*
** EPITECH PROJECT, 21/03/24
** testsGameInstance.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "../../../Games/IGame.hpp"

class TestsGame : public IGame {
public:
    TestsGame(int score = 55) : _score(score) {}
    ~TestsGame() = default;
    int getScore() override { return _score; }
    void startGame() override {}
    void stopGame() override {}
    void simulate() override {}
    void catchKeyEvent(int key) override {(void)key;}
    std::vector<std::shared_ptr<IEntity>> getEntities() override { return std::vector<std::shared_ptr<IEntity>>(); }
    std::vector<std::shared_ptr<IText>> getTexts() override { return std::vector<std::shared_ptr<IText>>(); }
    std::vector<std::shared_ptr<ISound>> getSounds() override { return std::vector<std::shared_ptr<ISound>>(); }
private:
    int _score;
};