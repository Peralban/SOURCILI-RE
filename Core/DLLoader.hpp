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
        lib = dlopen(path.c_str(), RTLD_LAZY);
        if (!lib)
            throw Exception();
    };
    ~DLLoader() {
        dlclose(lib);
    };

    T &getInstance() {
        using func = T *(*)();
        auto sym = reinterpret_cast<func>(dlsym(lib, "entry_point"));
        if (!sym)
            throw Exception();
        return sym();
    }
private:
    void *lib;
};
