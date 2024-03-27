/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Player.hpp
*/

#pragma once

#include "../AEntity.hpp"
#include "Snake.hpp"
#include <list>

class Player : public AEntity {
    public:
        Player();
        Player(size_t x, size_t y);
        ~Player();

        void move(Direction dir);
        int getPlayerSize() { return this->_player_size; }
        void setPlayerSize(int size) { this->_player_size = size; }
        std::list<std::shared_ptr<IEntity>> getTail() { return this->_tail; }
        void addTail(size_t x, size_t y);
        void removeTail();
        void setDirection(Direction dir) { this->direction = dir; }
        Direction getDirection() { return this->direction; }
    private:
        Direction direction;
        int _player_size;
        std::list<std::shared_ptr<IEntity>> _tail;
};