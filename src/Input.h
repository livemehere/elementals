#pragma once
#include "Window.h"


class Input {
    Window& window;

public:
    Input(Window &window);
    ~Input() = default;

    float xPos;
    float yPos;
    void update();
};
