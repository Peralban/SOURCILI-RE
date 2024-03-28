/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** No file there, just an epitech header example.
*/

#pragma once

#include <string>
#include <utility>
#include <dlfcn.h>
#include <functional>
#include <memory>

namespace Arcade {
    template <typename T>
    class DLLoader {
    public :
        class DLLoaderException : public std::exception {
        public :
            DLLoaderException(std::string const &msg) : _msg(msg) {};
            [[nodiscard]] const char *what() const noexcept override {
                return _msg.c_str();
            }
        private :
            std::string _msg;
        };

        class dlException : public DLLoaderException {
        public :
            dlException() : DLLoaderException(dlerror()) {};
        };

        class TypeException : public DLLoaderException {
        public :
            TypeException() : DLLoaderException("Invalid type") {};
        };

        DLLoader(const std::string path) {
            lib = dlopen(path.c_str(), RTLD_LAZY);
            if (!lib)
                throw dlException();
        }

        ~DLLoader() {
            if (lib)
                dlclose(lib);
        }

        T *getInstance(const std::string type) {
            if (type != "loadGameInstance" && type != "loadGraphicInstance")
                throw TypeException();
            auto sym = reinterpret_cast<T *(*)()>(dlsym(lib, type.c_str()));
            if (!sym)
                return nullptr;
            return sym();
        }
    private:
        void *lib;
    };
}