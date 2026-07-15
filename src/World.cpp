#include "World.h"

#include <iostream>
#include <vector>

#include <GLFW/glfw3.h>

#include "utils.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

World::World() {
    // VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    // EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // layout
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));
    glEnableVertexAttribArray(1);

    // shader
    program = utils::create_shader_program("shaders/basic.vert", "shaders/basic.frag");
    glUseProgram(program);
    modelLocation = glGetUniformLocation(program, "uModel");
    viewLocation = glGetUniformLocation(program, "uView");


    // texture
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D,texture);
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA8,
        textureW,
        textureH,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        pixel.data()
    );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // render as wireframe
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // disable back-face
    // NOTE: if two size object needed, turn of culling
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

}

World::~World() {
    glDeleteProgram(program);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}

void World::update() {

    transform.rotation.z = glfwGetTime() * 20;
    viewTransform.position.x = 1.0f;

    /* MODEL */
    model = glm::mat4(1.0f);

    // position
    model = glm::translate(model, transform.position);

    // rotation
    model = glm::rotate(model,glm::radians(transform.rotation.x),glm::vec3(1.0f,0.0f,0.0f));
    model = glm::rotate(model,glm::radians(transform.rotation.y),glm::vec3(0.0f,1.0f,0.0f));
    model = glm::rotate(model,glm::radians(transform.rotation.z),glm::vec3(0.0f,0.0f,1.0f));

    // scale
    model = glm::scale(model, transform.scale);

    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));

    /* VIEW */
    view = glm::mat4(1.0f);
    view = glm::translate(view, viewTransform.position);
    view = glm::inverse(view);
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
}

void World::render() {
    glUseProgram(program);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(),GL_UNSIGNED_INT,0);
}
