#pragma once

#include <array>
#include <vector>

// (modern) OpenGL
#include <GL/glew.h>

#include "config.h"
#include "vertex.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>

class Chunk {
public:
  Chunk(std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
                   CH_WIDTH>
            blocks,
        unsigned int x, unsigned int y, unsigned int shader);
  void render();

  void genVBO();
  void setBlock(unsigned int x, unsigned int y, unsigned int z,
                unsigned char block);
  unsigned char getBlock(unsigned int x, unsigned int y, unsigned int z);

private:
  std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
             CH_WIDTH>
      m_blocks;

  std::vector<vertex> m_chunk_vertices{};

  glm::mat4 m_model_matrix = glm::mat4(1.0f);

  unsigned int m_vbo;
  unsigned int m_model_matrix_location;
  unsigned int m_shader;

  unsigned int m_x;
  unsigned int m_y;
};
