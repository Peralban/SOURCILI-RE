/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Player.cpp
*/

#include "Player.hpp"

Player::Player() : AEntity("player", {0, 0}, {1, 1}, 0, 'O', std::make_shared<AColor>(255, 255, 255, 255))
{
    this->direction = Direction::TORIGHT;
    this->_player_size = 4;
    this->_tail = std::vector<std::shared_ptr<IEntity>>();
}

Player::Player(size_t x, size_t y) : AEntity("player", {x, y}, {1, 1}, 0, 'O', std::make_shared<AColor>(255, 255, 255, 255))
{
    this->direction = Direction::TORIGHT;
    this->_player_size = 4;
    this->_tail = std::vector<std::shared_ptr<IEntity>>();
}

void Player::addTail(size_t x, size_t y)
{
    this->_tail.push_back(std::make_shared<AEntity>("tail", std::vector<size_t>{x, y}, std::vector<size_t>{1, 1}, 0, 'o', std::make_shared<AColor>(255, 255, 255, 255)));
}

void Player::removeTail()
{
    this->_tail.pop_back();
}

void Player::move(Direction dir)
{
    this->addTail(this->getPos()[0], this->getPos()[1]);
    if (dir == Direction::UPWARD) {
        this->setPos(this->getPos()[0], this->getPos()[1] - 1);
    } else if (dir == Direction::DOWNWARD) {
        this->setPos(this->getPos()[0], this->getPos()[1] + 1);
    } else if (dir == Direction::TOLEFT) {
        this->setPos(this->getPos()[0] - 1, this->getPos()[1]);
    } else if (dir == Direction::TORIGHT) {
        this->setPos(this->getPos()[0] + 1, this->getPos()[1]);
    }
}

Player::~Player() {}