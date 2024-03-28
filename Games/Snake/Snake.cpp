/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"
#include "Player.hpp"
#include <chrono>
#include <thread>

void Snake::addFood(std::shared_ptr<IEntity> food)
{
    this->_food.push_back(food);
}

void Snake::removeFood(std::shared_ptr<IEntity> food)
{
    this->_food.remove(food);
}

void Snake::addWall(std::shared_ptr<IEntity> wall)
{
    this->_walls.push_back(wall);
}

Snake::Snake() : _score(0), _speed(1), _isRunning(false), _width(22), _height(28)
{
    this->setPlayer(std::make_shared<Player>(8, 7));
    this->_food = std::list<std::shared_ptr<IEntity>>();
    this->_walls = std::vector<std::shared_ptr<IEntity>>();
    this->addFood(createFood());
    this->addWall(std::make_shared<AEntity>("Assets/Snake/wall", std::vector<size_t>{0, 0}, std::vector<size_t>{29, 29}, 0, '+', std::make_shared<AColor>(0, 0, 0, 255)));
    this->addWall(std::make_shared<AEntity>("Assets/Snake/wall", std::vector<size_t>{0, this->getHeight() - 1}, std::vector<size_t>{29, 29}, 90, '+', std::make_shared<AColor>(0, 0, 0, 255)));
    this->addWall(std::make_shared<AEntity>("Assets/Snake/wall", std::vector<size_t>{this->getWidth() - 1, this->getHeight() - 1}, std::vector<size_t>{29, 29}, 180, '+', std::make_shared<AColor>(0, 0, 0, 255)));
    this->addWall(std::make_shared<AEntity>("Assets/Snake/wall", std::vector<size_t>{this->getWidth() - 1, 0}, std::vector<size_t>{29, 29}, 270, '+', std::make_shared<AColor>(0, 0, 0, 255)));
    for (size_t i = 1; i < this->getWidth() - 1; i++) {
        this->addWall(std::make_shared<AEntity>("Assets/Snake/wall", std::vector<size_t>{i, 0}, std::vector<size_t>{29, 29}, 0, '-', std::make_shared<AColor>(0, 0, 0, 255)));
        this->addWall(std::make_shared<AEntity>("Assets/Snake/wall", std::vector<size_t>{i, this->getHeight() - 1}, std::vector<size_t>{29, 29}, 0, '-', std::make_shared<AColor>(0, 0, 0, 255)));
    }
    for (size_t i = 1; i < this->getHeight() - 1; i++) {
        this->addWall(std::make_shared<AEntity>("Assets/Snake/wall", std::vector<size_t>{0, i}, std::vector<size_t>{29, 29}, 90, '|', std::make_shared<AColor>(0, 0, 0, 255)));
        this->addWall(std::make_shared<AEntity>("Assets/Snake/wall", std::vector<size_t>{this->getWidth() - 1, i}, std::vector<size_t>{29, 29}, 90, '|', std::make_shared<AColor>(0, 0, 0, 255)));
    }
    std::vector<std::shared_ptr<IEntity>> entities = std::vector<std::shared_ptr<IEntity>>();
    entities.push_back(std::make_shared<AEntity>("Assets/Snake/background", std::vector<size_t>{0, 0}, std::vector<size_t>{638, 812}, 0, '\0', std::make_shared<AColor>(255, 255, 255, 255)));
    this->_entities = entities;
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
        player->setRotation(180);
    } else if (key == Keys::S || key == Keys::DOWN) {
        player->setDirection(Direction::DOWNWARD);
        player->setRotation(0);
    } else if (key == Keys::Q || key == Keys::LEFT) {
        player->setDirection(Direction::TOLEFT);
        player->setRotation(270);
    } else if (key == Keys::D || key == Keys::RIGHT) {
        player->setDirection(Direction::TORIGHT);
        player->setRotation(90);
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
    srand(time(NULL));

    do {
        x = rand() % this->_width - 1;
        y = rand() % this->_height - 1;
        correctPos = true;
        if (x > this->getWidth() - 1 || y > this->getHeight() - 1)
            correctPos = false;
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
        if (x == 0 || x == this->getWidth() - 1 || y == 0 || y == this->getHeight() - 1)
            correctPos = false;
    } while (!correctPos);
    return std::make_shared<AEntity>("Assets/Snake/food", std::vector<size_t>{x, y}, std::vector<size_t>{29, 29}, 0, 'F', std::make_shared<AColor>(255, 0, 0, 255));
}

int Snake::simulate()
{
    static std::chrono::time_point<std::chrono::steady_clock> lastFrameTime = std::chrono::steady_clock::now();
    std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsedTime = currentTime - lastFrameTime;

    if (elapsedTime.count() <= 0.3f)
        return 0;
    if (this->_isRunning == false)
        return 0;
    Player *player = dynamic_cast<Player *>(this->getPlayer().get());
    player->move(player->getDirection());
    if (player->getPos()[1] == 0 || player->getPos()[1] == this->getHeight() - 1 || player->getPos()[0] == 0 || player->getPos()[0] == this->getWidth() - 1)
        return this->gameOver();
    for (auto &tail : player->getTail())
        if (player->getPos()[0] == tail->getPos()[0] && player->getPos()[1] == tail->getPos()[1])
            return this->gameOver();
    bool foodEaten = false;
    for (auto &food : this->getFood()) {
        if (player->getPos()[0] == food->getPos()[0] && player->getPos()[1] == food->getPos()[1]) {
            this->removeFood(food);
            this->addFood(this->createFood());
            foodEaten = true;
            player->setPlayerSize(player->getPlayerSize() + 1);
        }
    }
    if (foodEaten == false && player->getTail().size() >= player->getPlayerSize() - 1) {
        player->removeTail();
    }
    this->setScore(player->getPlayerSize());
    lastFrameTime = currentTime;
    return 0;
}

std::vector<std::shared_ptr<IEntity>> Snake::getEntities()
{
    std::vector<std::shared_ptr<IEntity>> entities = std::vector<std::shared_ptr<IEntity>>();
    for (auto &entity : this->getOtherEntities())
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

extern "C" {
    IGame *loadGameInstance()
    {
        return new Snake();
    }
}
