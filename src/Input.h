#pragma once
#include "Window.h"

enum class Key {
    ESC,
    W,
    A,
    S,
    D,
    Q,
    E,
};

struct MouseState {
    float screenX;
    float screenY;
    float prevScreenX;
    float prevScreenY;
    float deltaX;
    float deltaY;
    bool leftBtnDown;
    bool rightBtnDown;
    bool leftBtnPressed;
    bool rightBtnPressed;
    bool lock;
};

class Input {
    Window& window_;
    MouseState mouseState_{};
    bool firstMouseUpdate_ = true;

public:
    Input(Window &window);
    ~Input() = default;

    const MouseState& getMouseState() const {
        return mouseState_;
    }

    void update();
    void setCursorLockState(bool lock);

    bool isKeyDown(Key key) const;
};
