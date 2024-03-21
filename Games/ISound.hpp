/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ISound
*/

#pragma once

#include <string>

class ISound {
    public:
        virtual ~ISound() = default;

        //setters
        virtual void setPathSound(const std::string &pathSound) = 0;
        virtual void setVolume(float volume) = 0;
        virtual void setStatus(int status) = 0;

        //getters
        virtual std::string getPathSound() = 0;
        virtual float getVolume() const = 0;
        virtual int getStatus() const = 0;
};

// Sound
// std::string _pathMusic
// float _volume
// int _status   --> (START, LOOP, STOP, NONE)
