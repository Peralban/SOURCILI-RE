/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"
#include "Player.hpp"

void Snake::addFood(std::shared_ptr<IEntity> food)
{
    this->_food.push_back(food);
}

void Snake::addWall(std::shared_ptr<IEntity> wall)
{
    this->_walls.push_back(wall);
}

Snake::Snake() : _score(0), _speed(1), _isRunning(false), _width(17), _height(15)
{
    this->setPlayer(std::make_shared<Player>(8, 7));
    this->_food = std::vector<std::shared_ptr<IEntity>>();
    this->_walls = std::vector<std::shared_ptr<IEntity>>();
    this->addFood(createFood());
    this->addWall(std::make_shared<AEntity>("corner_wall", std::vector<size_t>{0, 0}, std::vector<size_t>{1, 1}, 0, '┌', std::make_shared<AColor>(0, 0, 0, 255)));
    this->addWall(std::make_shared<AEntity>("corner_wall", std::vector<size_t>{0, 14}, std::vector<size_t>{1, 1}, 90, '└', std::make_shared<AColor>(0, 0, 0, 255)));
    this->addWall(std::make_shared<AEntity>("corner_wall", std::vector<size_t>{16, 14}, std::vector<size_t>{1, 1}, 180, '┘', std::make_shared<AColor>(0, 0, 0, 255)));
    this->addWall(std::make_shared<AEntity>("corner_wall", std::vector<size_t>{16, 0}, std::vector<size_t>{1, 1}, 270, '┐', std::make_shared<AColor>(0, 0, 0, 255)));
    for (size_t i = 1; i < 17; i++) {
        this->addWall(std::make_shared<AEntity>("wall", std::vector<size_t>{i, 0}, std::vector<size_t>{1, 1}, 0, '─', std::make_shared<AColor>(0, 0, 0, 255)));
        this->addWall(std::make_shared<AEntity>("wall", std::vector<size_t>{i, 14}, std::vector<size_t>{1, 1}, 0, '─', std::make_shared<AColor>(0, 0, 0, 255)));
    }
    for (size_t i = 1; i < 15; i++) {
        this->addWall(std::make_shared<AEntity>("wall", std::vector<size_t>{0, i}, std::vector<size_t>{1, 1}, 90, '│', std::make_shared<AColor>(0, 0, 0, 255)));
        this->addWall(std::make_shared<AEntity>("wall", std::vector<size_t>{16, i}, std::vector<size_t>{1, 1}, 90, '│', std::make_shared<AColor>(0, 0, 0, 255)));
    }
    std::vector<std::shared_ptr<IEntity>> entities = std::vector<std::shared_ptr<IEntity>>();
    entities.push_back(std::make_shared<AEntity>("background", std::vector<size_t>{0, 0}, std::vector<size_t>{1, 1}, 0, '\0', std::make_shared<AColor>(255, 255, 255, 255)));
    //TEXT SCORE!!!
}

Snake::~Snake() {}

int Snake::startGame()
{
    this->_isRunning = true;
    return 0;
}

int Snake::stopGame()
{
    this->_isRunning = false;
    return 0;
}

void Snake::catchKeyEvent(int key)
{
    Player *player = dynamic_cast<Player *>(this->getPlayer().get());
    if (key == Keys::Z || key == Keys::UP) {
        player->setDirection(Direction::UPWARD);
    } else if (key == Keys::S || key == Keys::DOWN) {
        player->setDirection(Direction::DOWNWARD);
    } else if (key == Keys::Q || key == Keys::LEFT) {
        player->setDirection(Direction::TOLEFT);
    } else if (key == Keys::D || key == Keys::RIGHT) {
        player->setDirection(Direction::TORIGHT);
    }
}

int Snake::gameOver()
{
    this->_isRunning = false;
    //afficher filtre gris
    //afficher game over
    return 0;
}

std::shared_ptr<IEntity> Snake::createFood()
{
    size_t x, y;
    bool correctPos;

    do {
        x = rand() % this->_width;
        y = rand() % this->_height;
        correctPos = true;
        for (auto &tail : dynamic_cast<Player *>(this->getPlayer().get())->getTail()) {
            if (x == tail->getPos()[0] && y == tail->getPos()[1]) {
                correctPos = false;
                break;
            }
        }
        if (this->getPlayer()->getPos()[0] == x && this->getPlayer()->getPos()[1] == y)
            correctPos = false;
        for (auto &food : this->getFood()) {
            if (x == food->getPos()[0] && y == food->getPos()[1]) {
                correctPos = false;
                break;
            }
        }
    } while (!correctPos);
    std::string foodChoices = "🍇🍎🍏🍑🍊🍋🍍🍐🍒🍓🥝";
    size_t randomIndex = rand() % foodChoices.size();
    return std::make_shared<AEntity>("food", std::vector<size_t>{x, y}, std::vector<size_t>{1, 1}, 0, foodChoices[randomIndex], std::make_shared<AColor>(255, 0, 0, 255));
}

int Snake::simulate()
{
    if (this->_isRunning == false)
        return 0;
    Player *player = dynamic_cast<Player *>(this->getPlayer().get());
    player->move(player->getDirection());
    if (player->getPos()[0] == 0 || player->getPos()[0] == 16 || player->getPos()[1] == 0 || player->getPos()[1] == 14)
        return this->gameOver();
    for (auto &tail : player->getTail())
        if (player->getPos()[0] == tail->getPos()[0] && player->getPos()[1] == tail->getPos()[1])
            return this->gameOver();
    bool foodEaten = false;
    for (auto &food : this->getFood()) {
        if (player->getPos()[0] == food->getPos()[0] && player->getPos()[1] == food->getPos()[1]) {
            this->addFood(this->createFood());
            foodEaten = true;
            player->setPlayerSize(player->getPlayerSize() + 1);
        }
    }
    if (foodEaten == false)
        player->removeTail();
    this->setScore(player->getPlayerSize());
    return 0;
}

std::vector<std::shared_ptr<IEntity>> Snake::getEntities()
{
    std::vector<std::shared_ptr<IEntity>> entities = std::vector<std::shared_ptr<IEntity>>();
    for (auto &entity : this->getEntities())
        entities.push_back(entity);
    entities.push_back(this->getPlayer());
    for (auto &tail : dynamic_cast<Player *>(this->getPlayer().get())->getTail())
        entities.push_back(tail);
    for (auto &food : this->getFood())
        entities.push_back(food);
    for (auto &wall : this->getWalls())
        entities.push_back(wall);
    return entities;
}
