#include "Window.h"

int main() {

    Window win;
    win.init();
    win.create_window(1280, 720, "Elementals", true);

    while (!win.should_close()) {
       // logic

        win.update();
    }

    return 0;
}