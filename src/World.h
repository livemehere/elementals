#pragma once

#include <vector>
#include <glad/glad.h>

struct Vertex {
    float x;
    float y;
    float z;
};

class World {
private:
   std::vector<Vertex> vertices = {
       { -1.0f, -1.0f, 0.0f}, // left bottom
       { 1.0f, -1.0f, 0.0f}, // right bottom
       { -1.0f, 1.0f, 0.0f}, // left top
       { 1.0f, 1.0f, 0.0f}, // right top
   };
    std::vector<int> indices = {
       0,1,2,
       1,2,3
    };

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    GLuint program;

public:
    World();
    ~World();

    void update();
    void render();
};
