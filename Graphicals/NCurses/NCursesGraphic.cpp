/*
** EPITECH PROJECT, 2024
** SOURCILI-RE
** File description:
** No file there , just an epitech header example .
*/

#include "NCursesGraphic.hpp"

NCursesGraphic::NCursesGraphic()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    //activate arrow keys
    //init_pair(1, COLOR_RED, COLOR_BLACK);
    //init_pair(2, COLOR_GREEN, COLOR_BLACK);
    //init_pair(4, COLOR_BLUE, COLOR_BLACK);
}

NCursesGraphic::~NCursesGraphic()
{
    endwin();
}

bool NCursesGraphic::isWindowOpen() const
{
    return true;
}

void NCursesGraphic::closeWindow()
{
    endwin();
}

void NCursesGraphic::clearWindow()
{
    clear();
}

int NCursesGraphic::getKeyEvent()
{
    int key = getch();
    return (int)keyMapNcurses[key];
}

void NCursesGraphic::displayWindow()
{
    refresh();
}

void NCursesGraphic::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        mvaddch(entity->getPos()[1], entity->getPos()[0], entity->getChar());
    }
}

void NCursesGraphic::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts) {
        mvprintw(text->getPos()[1], text->getPos()[0], text->getText().c_str());
    }
}

void NCursesGraphic::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    //for (auto &sound : sounds) {
    //    sound->playSound();
    //}
    (void)sounds;
    return;
}

extern "C" IGraphic *loadGraphicInstance()
{
    return new NCursesGraphic();
}
