#pragma once
#include <span>
#include <glad/glad.h>


/* RGBA support only for simplicity */
class Texture2D {
private:
   GLuint id_;
   int width_ = 0;
   int height_ = 0;
public:
   Texture2D(int width, int height, std::span<const uint8_t> pixels);
   ~Texture2D() {
      if (id_ != 0) {
        glDeleteTextures(1, &id_);
      }
   }

   Texture2D(const Texture2D&) = delete;
   Texture2D&operator=(const Texture2D&) = delete;

   void bind() const {
      glBindTexture(GL_TEXTURE_2D, id_);
  }
};

