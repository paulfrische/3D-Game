#pragma once

#include <array>
#include <vector>

// (modern) OpenGL
#include <GL/glew.h>

#include "config.h"
#include "vertex.hpp"

class Chunk {
public:
  Chunk(std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
                   CH_WIDTH>
            blocks,
        unsigned int x, unsigned int y);
  void render();
  void genVBO();
  void setBlock(unsigned int x, unsigned int y, unsigned int z,
                unsigned char block);

private:
  std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
             CH_WIDTH>
      m_blocks;

  std::vector<vertex> m_chunk_vertices {};

  unsigned int m_vbo;
  unsigned int m_x;
  unsigned int m_y;

};
