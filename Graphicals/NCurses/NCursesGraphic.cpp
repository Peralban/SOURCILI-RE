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

    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_YELLOW, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
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

short NCursesGraphic::getNcursesColor(short R, short G, short B)
{
    short r = R > 128 ? 255 : 0;
    short g = G > 128 ? 255 : 0;
    short b = B > 128 ? 255 : 0;

    if (r == 0 && g == 0 && b == 0)
        return 1;
    else if (r == 0 && g == 0 && b == 255)
        return 2;
    else if (r == 0 && g == 255 && b == 0)
        return 3;
    else if (r == 0 && g == 255 && b == 255)
        return 4;
    else if (r == 255 && g == 0 && b == 0)
        return 5;
    else if (r == 255 && g == 0 && b == 255)
        return 6;
    else if (r == 255 && g == 255 && b == 0)
        return 7;
    else if (r == 255 && g == 255 && b == 255)
        return 8;
    else
        return 1;
}

void NCursesGraphic::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        short R = entity->getColor()->getR();
        short G = entity->getColor()->getG();
        short B = entity->getColor()->getB();
        short ncursesColor = getNcursesColor(R, G, B);
        attron(COLOR_PAIR(ncursesColor));
        mvaddch(entity->getPos()[1], entity->getPos()[0], entity->getChar());
        attroff(COLOR_PAIR(ncursesColor));
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
