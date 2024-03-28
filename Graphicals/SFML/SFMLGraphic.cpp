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

bool SFMLGraphic::isWindowOpen() const
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

sf::Texture scaleTexture(const sf::Texture& texture, unsigned int width, unsigned int height) {
    sf::Sprite sprite(texture);
    sf::RenderTexture newTexture;
    float x = static_cast<float>(width) / texture.getSize().x;
    float y = static_cast<float>(height) / texture.getSize().y;

    sprite.setScale(x, y);
    newTexture.create(width, height);
    newTexture.clear(sf::Color::Transparent);
    newTexture.draw(sprite);
    newTexture.display();
    return newTexture.getTexture();
}

void SFMLGraphic::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        sf::Sprite sprite;
        sf::Texture texture;

        texture.loadFromFile(entity->getPath() + ".png");
        texture.setSmooth(true);
        texture = scaleTexture(texture, entity->getSize()[0], entity->getSize()[1]);
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
        sfText.setPosition(text->getPos()[0] * _caseSize, text->getPos()[1] * _caseSize);
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

extern "C" {
    std::unique_ptr<IGraphic> loadGraphicInstance()
    {
        return std::make_unique<SFMLGraphic>();
    }
}