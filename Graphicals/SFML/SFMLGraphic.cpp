/*
** EPITECH PROJECT, 2024
** Arcade SFML
** File description:
** SFMLGraphic.cpp
*/

#include "SFMLGraphic.hpp"

SFMLGraphic::SFMLGraphic()
{
    _window.create(sf::VideoMode(_dimensions[0], _dimensions[1]), "Arcade");
    _window.setFramerateLimit(60);
}

bool SFMLGraphic::isWindowOpen()
{
    return _window.isOpen();
}

void SFMLGraphic::closeWindow()
{
    _window.close();
}

void SFMLGraphic::clearWindow()
{
    _window.clear();
}

void SFMLGraphic::displayWindow()
{
    _window.display();
}

int SFMLGraphic::getKeyEvent() {
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::KeyPressed) {
            auto it = _keyMap.find(_event.key.code);
            if (it != _keyMap.end()) {
                return it->second;
            }
        }
    }
    return Keys::UNKNOWN;
}

void SFMLGraphic::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        sf::Sprite sprite;
        sf::Texture texture;
        texture.loadFromFile(entity->getPath() + ".png");
        sprite.setTexture(texture);
        sprite.setPosition(entity->getPos()[0] * _caseSize, entity->getPos()[1] * _caseSize);
        _window.draw(sprite);
    }
}

void SFMLGraphic::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts) {
        sf::Text sfText;
        sf::Font font;
        font.loadFromFile(text->getFontPath() + ".ttf");
        sfText.setFont(font);
        sfText.setString(text->getText());
        sfText.setCharacterSize(text->getSize());
        sfText.setFillColor(sf::Color(text->getColor()->getR(), text->getColor()->getG(), text->getColor()->getB(), text->getColor()->getA()));
        sfText.setPosition(text->getPos()[0], text->getPos()[1]);
        _window.draw(sfText);
    }
}

void SFMLGraphic::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    for (auto &sound : sounds) {
        sf::SoundBuffer buffer;
        buffer.loadFromFile(sound->getPathSound() + ".wav");
        sf::Sound sfSound;
        sfSound.setBuffer(buffer);
        sfSound.play();
    }
}
