/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Snake.hpp
*/

#pragma once

#include "../AGame.hpp"

enum Direction {
    UPWARD,
    DOWNWARD,
    TOLEFT,
    TORIGHT
};

class Snake : public AGame {
    public:
        Snake();
        ~Snake();

        int startGame() override;
        int stopGame() override;
        int getScore() override {return _score;}
        int simulate() override;
        int gameOver();

        void catchKeyEvent(int key) override;

        void setPlayer(std::shared_ptr<IEntity> player) {_player = player;}
        void setFood(std::vector<std::shared_ptr<IEntity>> food) {_food = food;}
        void addFood(std::shared_ptr<IEntity> food);
        void setWalls(std::vector<std::shared_ptr<IEntity>> walls) {_walls = walls;}
        void addWall(std::shared_ptr<IEntity> wall);
        void setSpeed(int speed) {_speed = speed;}
        void setIsRunning(bool isRunning) {_isRunning = isRunning;}
        void setWidth(int width) {_width = width;}
        void setHeight(int height) {_height = height;}
        int getWidth() {return _width;}
        int getHeight() {return _height;}
        bool isRunning() {return _isRunning;}
        int getSpeed() {return _speed;}
        std::shared_ptr<IEntity> getPlayer() {return _player;}
        std::vector<std::shared_ptr<IEntity>> getFood() {return _food;}
        std::vector<std::shared_ptr<IEntity>> getWalls() {return _walls;}
        std::vector<std::shared_ptr<IEntity>> getEntities();

        std::shared_ptr<IEntity> createFood();

    private:
        std::shared_ptr<IEntity> _player;
        std::vector<std::shared_ptr<IEntity>> _food;
        std::vector<std::shared_ptr<IEntity>> _walls;
        int _score;
        int _speed;
        bool _isRunning;
        int _width;
        int _height;
};