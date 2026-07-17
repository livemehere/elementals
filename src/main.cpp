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
            const Size size = win.get_size();

            win.before_update();

            input.update();
            world.update();
            world.render();

            ImGui::SetNextWindowSize(ImVec2(250,80), ImGuiCond_Once);
            ImGui::Begin("Debug");
            ImGui::Text("size : %dx%d", size.w, size.h);
            ImGui::Text("buffer size : %dx%d", size.fb_w, size.fb_h);
            ImGui::Text("cursor pos : %.2fx%.2f", input.xPos, input.yPos);
            ImGui::End();

            win.update();
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}
