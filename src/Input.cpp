#include "Input.h"

#include <GLFW/glfw3.h>

Input::Input(Window &window) : window(window) {}

void Input::update() {
    double x,y;
    glfwGetCursorPos(window.get(), &x, &y);
    xPos = (float)x;
    yPos = (float)y;
}
