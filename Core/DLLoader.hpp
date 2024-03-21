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
        Exception() : _msg(dlerror()) {};
        [[nodiscard]] const char *what() const noexcept override {
                return _msg.c_str();
        }
    private :
        std::string _msg;
    };

    DLLoader(const std::string &path) {
        lib = std::unique_ptr<void, decltype(&dlclose)>(dlopen(path.c_str(), RTLD_LAZY), dlclose);
        if (!lib)
            throw Exception();
    };
    
    ~DLLoader() {
        if (lib)
            dlclose(lib);
    };

    std::unique_ptr<T> getInstance() {
        function<std::unique_ptr<T>()> sym;

        sym = (std::unique_ptr<T>(*)())(dlsym(lib, "loadInstance"));
        if (!sym)
            throw Exception();
        return sym();
    }
private:
    std::unique_ptr<void, decltype(&dlclose)> lib;
};
