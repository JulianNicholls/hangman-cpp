#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include "raylib.h"

struct Window
{
    Window(int _width, int _height, std::string_view title)
        : width{_width}
        , height{_height}
    {
        ::InitWindow(width, height, std::string(title).c_str());
    }

    ~Window()
    {
        ::CloseWindow();
    }

    int width;
    int height;
};
#endif // WINDOW_H
