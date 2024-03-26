/*
** EPITECH PROJECT, 2024
** SOURCILI-RE
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include <ncurses.h>
#include "../IGraphic.hpp"

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