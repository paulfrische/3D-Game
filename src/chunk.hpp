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

  void setBlock(unsigned int x, unsigned int y, unsigned int z,
                unsigned char block);
  unsigned char getBlock(unsigned int x, unsigned int y, unsigned int z);

  unsigned int m_vbo;

  std::vector<vertex> m_chunk_vertices;
  std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
             CH_WIDTH>
      m_blocks;

private:
  glm::mat4 m_model_matrix = glm::mat4(1.0f);

  unsigned int m_model_matrix_location;
  unsigned int m_shader;

  unsigned int m_x;
  unsigned int m_y;
};

class ChunkManager {
public:
  ChunkManager(unsigned int shader);
  ~ChunkManager();

  void generateWorld();
  void render();
  void genVBOs();

  unsigned char getBlock(unsigned int x, unsigned y, unsigned z);
  unsigned char setBlock(unsigned int x, unsigned y, unsigned z,
                         unsigned char block);

private:
  std::vector<std::vector<Chunk *>> m_chunks{};
  unsigned int m_shader;
};
