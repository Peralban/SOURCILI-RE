/*
** EPITECH PROJECT, 18/03/24
** AEntity.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include "IEntity.hpp"

class AEntity : public IEntity {
    public:
        AEntity(std::string texturePath, std::vector<std::size_t> pos, std::vector<std::size_t> size, float rotation);
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
        std::shared_ptr<IColor> getColor() const override { return _color->getColor(); }
        std::string getPath() const override { return _path; }
        float getRotation() const override { return _rotate; }

    protected:
        std::vector<std::size_t> _pos;
        std::vector<std::size_t> _size;
        char _character;
        std::unique_ptr<IColor> _color;
        std::string _path;
        float _rotate;
};
