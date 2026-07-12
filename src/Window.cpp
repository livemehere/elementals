#include "Window.h"
#include <iostream>
#include <format>

namespace {
    void error_callback(int error, const char* desc) {
        std::cout << std::format("Error: {}", desc) << std::endl;
    }
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::init() {
    if (!glfwInit()) {
        std::cout << "glfw init failed" << std::endl;
        exit(-1);
    }
    glfwSetErrorCallback(error_callback);
}

void Window::create_window(int w, int h, const std::string &title, bool vsync) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

    window = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
    if (!window) {
        glfwDestroyWindow(window);
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    glfwSwapInterval(vsync ? 1 : 0);

}

bool Window::should_close() const {
    return glfwWindowShouldClose(window);
}

void Window::update() const {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

