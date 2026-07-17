#include "common.h"

#include <iostream>
#include <imgui.h>

#include "Input.h"
#include "Window.h"
#include "World.h"


int main() {

    try {
        Window win;
        win.init();
        win.create_window(1280, 720, "Elementals", true);

        Input input{win};
        World world{win, input};

        while (!win.should_close()) {
            const Size& size = win.get_size();
            const MouseState& mouseState = input.getMouseState();

            win.before_update();

            input.update();
            world.update();
            world.render();

            ImGui::SetNextWindowSize(ImVec2(250,150), ImGuiCond_Once);
            ImGui::Begin("Debug");
            ImGui::Text("size : %dx%d", size.w, size.h);
            ImGui::Text("buffer size : %dx%d", size.fb_w, size.fb_h);
            ImGui::Text("screen pos : %.2fx%.2f", mouseState.screenX,mouseState.screenY);
            ImGui::Text("cursor delta : %.2fx%.2f", mouseState.deltaX,mouseState.deltaY);

            auto leftStateStr = std::format("Left : {}", mouseState.leftBtnDown ? "Pressed" : "NONE");
            ImGui::Text(leftStateStr.c_str());

            auto rightStateStr = std::format("Right : {}", mouseState.rightBtnDown ? "Pressed" : "NONE");
            ImGui::Text(rightStateStr.c_str());

            ImGui::End();

            input.setCursorLockState(mouseState.leftBtnDown);

            win.update();
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}
