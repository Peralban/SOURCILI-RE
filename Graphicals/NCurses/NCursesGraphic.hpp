/*
** EPITECH PROJECT, 2024
** SOURCILI-RE
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include <ncurses.h>
#include "../IGraphic.hpp"
#include <unordered_map>

class NCursesGraphic : public IGraphic {
public:
    NCursesGraphic();
    ~NCursesGraphic();

    //Window
    bool isWindowOpen() const override;
    void closeWindow() override;
    void clearWindow() override;

    //Event
    int getKeyEvent() override;

    //Display
    void displayWindow() override;
    void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) override;
    void displayText(std::vector<std::shared_ptr<IText>> texts) override;
    void playSound(std::vector<std::shared_ptr<ISound>> sounds) override;
};

static std::unordered_map<int, Keys> keyMapNcurses = {
    {KEY_UP, Keys::UP},
    {KEY_DOWN, Keys::DOWN},
    {KEY_LEFT, Keys::LEFT},
    {KEY_RIGHT, Keys::RIGHT},
    {10, Keys::ENTER},
    {32, Keys::SPACE},
    {27, Keys::ESCAPE},
    {97, Keys::A},
    {98, Keys::B},
    {99, Keys::C},
    {100, Keys::D},
    {101, Keys::E},
    {102, Keys::F},
    {103, Keys::G},
    {104, Keys::H},
    {105, Keys::I},
    {106, Keys::J},
    {107, Keys::K},
    {108, Keys::L},
    {109, Keys::M},
    {110, Keys::N},
    {111, Keys::O},
    {112, Keys::P},
    {113, Keys::Q},
    {114, Keys::R},
    {115, Keys::S},
    {116, Keys::T},
    {117, Keys::U},
    {118, Keys::V},
    {119, Keys::W},
    {120, Keys::X},
    {121, Keys::Y},
    {122, Keys::Z},
    {48, Keys::ZERO},
    {49, Keys::ONE},
    {50, Keys::TWO},
    {51, Keys::THREE},
    {52, Keys::FOUR},
    {53, Keys::FIVE},
    {54, Keys::SIX},
    {55, Keys::SEVEN},
    {56, Keys::EIGHT},
    {57, Keys::NINE}
};
