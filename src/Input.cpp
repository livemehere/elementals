#include "Input.h"

#include <GLFW/glfw3.h>

namespace {
    int toGlKey(const Key key) {
        switch (key) {
            case Key::ESC: return GLFW_KEY_ESCAPE;
            case Key::W: return GLFW_KEY_W;
            case Key::A: return GLFW_KEY_A;
            case Key::S: return GLFW_KEY_S;
            case Key::D: return GLFW_KEY_D;
            case Key::Q: return GLFW_KEY_Q;
            case Key::E: return GLFW_KEY_E;
        }
        return GLFW_KEY_UNKNOWN;
    }
}

Input::Input(Window &window) : window_(window) {}

void Input::update() {
    GLFWwindow* nativeWindow = window_.get();
    const WindowSize size = window_.get_size();

    /* MOUSE POSITION */
    double x,y;
    glfwGetCursorPos(nativeWindow, &x, &y);
    mouseState_.screenX = (float)x * size.fb_w / size.w;
    mouseState_.screenY = (float)y * size.fb_h / size.h;
    if (firstMouseUpdate_) {
        mouseState_.deltaX = 0.0f;
        mouseState_.deltaY = 0.0f;
        mouseState_.prevScreenX = mouseState_.screenX;
        mouseState_.prevScreenY = mouseState_.screenY;
        firstMouseUpdate_ = false;
    } else {
        mouseState_.deltaX = mouseState_.screenX - mouseState_.prevScreenX;
        mouseState_.deltaY = mouseState_.screenY - mouseState_.prevScreenY;
        mouseState_.prevScreenX = mouseState_.screenX;
        mouseState_.prevScreenY = mouseState_.screenY;
    }

    /* MOUSE BUTTONS */
    const int leftBtnDown = glfwGetMouseButton(nativeWindow, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
    mouseState_.leftBtnPressed = leftBtnDown && !mouseState_.leftBtnDown;
    mouseState_.leftBtnDown = leftBtnDown;

    const int rightBtnDown = glfwGetMouseButton(nativeWindow, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
    mouseState_.rightBtnPressed = rightBtnDown && !mouseState_.rightBtnDown;
    mouseState_.rightBtnDown = rightBtnDown;


}

void Input::setCursorLockState(bool lock) {
    if (mouseState_.lock == lock) return;
    mouseState_.lock = lock;
    glfwSetInputMode(window_.get(), GLFW_CURSOR, lock ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);

    firstMouseUpdate_ = true;
}

bool Input::isKeyDown(Key key) const {
    return glfwGetKey(window_.get(),toGlKey(key)) == GLFW_PRESS;
}
