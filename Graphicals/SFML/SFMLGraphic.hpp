/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SFMLGraphic.hpp
*/

#pragma once

#include "../IGraphic.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>

class SFMLGraphic : public IGraphic {
    public:
        SFMLGraphic();
        ~SFMLGraphic() = default;

        bool isWindowOpen();
        void closeWindow();
        void clearWindow();

        int getKeyEvent();

        void displayWindow();
        void displayEntities(std::vector<std::shared_ptr<IEntity>> entities);
        virtual void displayText(std::vector<std::shared_ptr<IText>> texts);
        virtual void playSound(std::vector<std::shared_ptr<ISound>> sounds);

        sf::Event getEvent() const { return _event; }
        void setEvent(sf::Event event) { _event = event; }

        sf::RenderWindow _window;

    private:
        sf::Event _event;
        std::vector<std::size_t> _dimensions = {725, 899};
        int _caseSize = 29;
        const std::unordered_map<sf::Keyboard::Key, Keys> _keyMap = {
            {sf::Keyboard::A, Keys::A},
            {sf::Keyboard::B, Keys::B},
            {sf::Keyboard::C, Keys::C},
            {sf::Keyboard::D, Keys::D},
            {sf::Keyboard::E, Keys::E},
            {sf::Keyboard::F, Keys::F},
            {sf::Keyboard::G, Keys::G},
            {sf::Keyboard::H, Keys::H},
            {sf::Keyboard::I, Keys::I},
            {sf::Keyboard::J, Keys::J},
            {sf::Keyboard::K, Keys::K},
            {sf::Keyboard::L, Keys::L},
            {sf::Keyboard::M, Keys::M},
            {sf::Keyboard::N, Keys::N},
            {sf::Keyboard::O, Keys::O},
            {sf::Keyboard::P, Keys::P},
            {sf::Keyboard::Q, Keys::Q},
            {sf::Keyboard::R, Keys::R},
            {sf::Keyboard::S, Keys::S},
            {sf::Keyboard::T, Keys::T},
            {sf::Keyboard::U, Keys::U},
            {sf::Keyboard::V, Keys::V},
            {sf::Keyboard::W, Keys::W},
            {sf::Keyboard::X, Keys::X},
            {sf::Keyboard::Y, Keys::Y},
            {sf::Keyboard::Z, Keys::Z},
            {sf::Keyboard::Escape, Keys::ESCAPE},
            {sf::Keyboard::Tab, Keys::TAB},
            {sf::Keyboard::LShift, Keys::SHIFT},
            {sf::Keyboard::LControl, Keys::CONTROL},
            {sf::Keyboard::Space, Keys::SPACE},
            {sf::Keyboard::Enter, Keys::ENTER},
            {sf::Keyboard::BackSpace, Keys::BACKSPACE},
            {sf::Keyboard::Up, Keys::UP},
            {sf::Keyboard::Down, Keys::DOWN},
            {sf::Keyboard::Left, Keys::LEFT},
            {sf::Keyboard::Right, Keys::RIGHT},
            {sf::Keyboard::Num0, Keys::ZERO},
            {sf::Keyboard::Num1, Keys::ONE},
            {sf::Keyboard::Num2, Keys::TWO},
            {sf::Keyboard::Num3, Keys::THREE},
            {sf::Keyboard::Num4, Keys::FOUR},
            {sf::Keyboard::Num5, Keys::FIVE},
            {sf::Keyboard::Num6, Keys::SIX},
            {sf::Keyboard::Num7, Keys::SEVEN},
            {sf::Keyboard::Num8, Keys::EIGHT},
            {sf::Keyboard::Num9, Keys::NINE}
        };
};
