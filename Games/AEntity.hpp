/*
** EPITECH PROJECT, 18/03/24
** AEntity.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IEntity.hpp"

class AColor : public IColor {
    public:
        AColor(int r, int g, int b, int a) {
            _r = r;
            _g = g;
            _b = b;
            _a = a;
        }
        AColor(const AColor &color) {
            _r = color._r;
            _g = color._g;
            _b = color._b;
            _a = color._a;
        }
        AColor() {
            _r = 0;
            _g = 0;
            _b = 0;
            _a = 0;
        }
        ~AColor() {}

        void setColor(short r, short g, short b, short a) {
            _r = r;
            _g = g;
            _b = b;
            _a = a;
        }
        void setR(short r) { _r = r; }
        void setG(short g) { _g = g; }
        void setB(short b) { _b = b; }
        void setA(short a) { _a = a; }

        //getters
        short getR() { return _r; }
        short getG() { return _g; }
        short getB() { return _b; }
        short getA() { return _a; }

    protected:
        short _r;
        short _g;
        short _b;
        short _a;
};

class AEntity : public IEntity {
    public:
        AEntity(std::string texturePath, std::vector<std::size_t> pos, std::vector<std::size_t> size, float rotation, char c, std::shared_ptr<IColor> color) {
            _path = texturePath;
            _pos = pos;
            _size = size;
            _rotate = rotation;
            _character = c;
            _color = color;
        }
        ~AEntity() = default;

        //setters
        void setPos(std::size_t x, std::size_t y) override { _pos = {x, y}; }
        void setSize(std::size_t x, std::size_t y) override { _size = {x, y}; }
        void setChar(char c) override { _character = c; }
        void setColor(std::unique_ptr<IColor> color) override { _color = std::move(color); }
        void setPath(const std::string &path) override { _path = path; }
        void setRotation(float rotation) override { _rotate = rotation; }

        //getters
        std::vector<std::size_t> getPos() const override { return _pos; }
        std::vector<std::size_t> getSize() const override { return _size; }
        int getChar() const override { return _character; }
        std::shared_ptr<IColor> getColor() const override { return _color; }
        std::string getPath() const override { return _path; }
        float getRotation() const override { return _rotate; }

    protected:
        std::vector<std::size_t> _pos;
        std::vector<std::size_t> _size;
        char _character;
        std::shared_ptr<IColor> _color;
        std::string _path;
        float _rotate;
};
