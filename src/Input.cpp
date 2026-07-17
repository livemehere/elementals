#include "Input.h"

#include <GLFW/glfw3.h>

Input::Input(Window &window) : window_(window) {}

void Input::update() {
    GLFWwindow* nativeWindow = window_.get();
    const Size size = window_.get_size();

    /* MOUSE POSITION */
    double x,y;
    glfwGetCursorPos(nativeWindow, &x, &y);
    mouseState_.x = (float)x * size.fb_w / size.w;
    mouseState_.y = (float)y * size.fb_h / size.h;
    mouseState_.deltaX = mouseState_.x - mouseState_.prevX;
    mouseState_.deltaY = mouseState_.y - mouseState_.prevY;
    mouseState_.prevX = mouseState_.x;
    mouseState_.prevY = mouseState_.y;

    /* MOUSE BUTTONS */
    int leftBtnState = glfwGetMouseButton(nativeWindow, GLFW_MOUSE_BUTTON_LEFT);
    if (leftBtnState == GLFW_PRESS) {
        mouseState_.leftBtnPressed = true;
    } else {
        mouseState_.leftBtnPressed = false;
    }

    int rightBtnState = glfwGetMouseButton(nativeWindow, GLFW_MOUSE_BUTTON_RIGHT);
    if (rightBtnState == GLFW_PRESS) {
        mouseState_.rightBtnPressed = true;
    } else {
        mouseState_.rightBtnPressed = false;
    }
}
