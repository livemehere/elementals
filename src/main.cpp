#include "common.h"

#include <iostream>
#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>

#include "Input.h"
#include "Window.h"
#include "World.h"
#include "core/Camera.h"


int main() {

    try {
        Window win;
        win.init();
        win.create_window(1280, 720, "Elementals", true);

        Input input{win};
        Camera camera;
        camera.projection = PerspectiveProjection{};
        // camera.projection = OrthoGraphicProjection{};
        World world{win, input};

        while (!win.should_close()) {
            const WindowSize& size = win.get_size();
            const MouseState& mouseState = input.getMouseState();

            win.before_update();

            camera.update();
            input.update();
            world.update(camera.getViewMatrix(), camera.getProjectionMatrix(size));
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

            ImGui::Begin("Camera");
            ImGui::DragFloat3("position", glm::value_ptr(camera.transform.position), 1.0f);
            ImGui::DragFloat3("rotation", glm::value_ptr(camera.transform.rotation), 1.0f);
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
