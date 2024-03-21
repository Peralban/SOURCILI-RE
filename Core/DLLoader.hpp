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

template <typename T>
class DLLoader {
public :
    class Exception : public std::exception {
    public :
        Exception(std::string const &msg) : _msg(msg) {};
        [[nodiscard]] const char *what() const noexcept override {
            return _msg.c_str();
        }
    private :
        std::string _msg;
    };

    class dlException : public Exception {
    public :
        dlException() : Exception(dlerror()) {};
    };

    class TypeException : public Exception {
    public :
        TypeException() : Exception("Invalid type") {};
    };

    DLLoader(const std::string path) {
        lib = std::unique_ptr<void, decltype(&dlclose)>(dlopen(path.c_str(), RTLD_LAZY), dlclose);
        if (!lib)
            throw dlException();
    };
    
    ~DLLoader() {
        if (lib)
            dlclose(lib.get());
    };

    std::unique_ptr<T> getInstance(const std::string type) {
        std::function<std::unique_ptr<T>()> sym;

        if (type != "loadGameInstance" && type != "loadGraphicInstance")
            throw TypeException();
        sym = (std::unique_ptr<T>(*)())(dlsym(lib.get(), type.c_str()));
        if (!sym)
            throw dlException();
        return sym();
    }
private:
    std::unique_ptr<void, decltype(&dlclose)> lib;
};
