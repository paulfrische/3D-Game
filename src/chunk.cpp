// (modern) OpenGL
#include <GL/glew.h>

#include <iostream>
#include <array>
#include <vector>

#include "chunk.hpp"
#include "block.hpp"
#include "config.h"

Chunk::Chunk(
    std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
               CH_WIDTH>
        blocks,
    unsigned int x, unsigned int y) {
  m_blocks = blocks;
  m_x = x;
  m_y = y;
}

void Chunk::render() {
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glDrawArrays(GL_TRIANGLES, 0, m_chunk_vertices.size());
}

void Chunk::setBlock(unsigned int x, unsigned int y, unsigned int z,
                            unsigned char block) {
  m_blocks[x][y][z] = block;
}

void Chunk::genVBO() {
  glGenBuffers(1, &m_vbo);
  m_chunk_vertices.clear();
  for (int x = 0; x < CH_WIDTH; x++) {
    for (int y = 0; y < CH_HEIGHT; y++) {
      for (int z = 0; z < CH_DEPTH; z++) {
        unsigned char block = m_blocks[x][y][z];
        if (block != 0) {
          // TODO: add block buffer logic thingy
            if ((x > 0 && m_blocks[x-1][y][z] == 0) || x == 0)
            {
                /* std::cout << "breakfast\n"; */
                std::array<vertex, 6> face = Face(BlockFace::EAST, x, y, z);
                m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face), end(face));
            }

            if ((x < CH_WIDTH && m_blocks[x+1][y][z] == 0) || x == CH_WIDTH)
            {
                /* std::cout << "breakfast\n"; */
                std::array<vertex, 6> face = Face(BlockFace::WEST, x, y, z);
                m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face), end(face));
            }

            if ((y > 0 && m_blocks[x][y-1][z] == 0) || y == 0)
            {
                /* std::cout << "breakfast\n"; */
                std::array<vertex, 6> face = Face(BlockFace::BOTTOM, x, y, z);
                m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face), end(face));
            }

            if ((y < CH_HEIGHT && m_blocks[x][y+1][z] == 0) || y == CH_HEIGHT)
            {
                /* std::cout << "breakfast\n"; */
                std::array<vertex, 6> face = Face(BlockFace::TOP, x, y, z);
                m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face), end(face));
            }

            if ((z > 0 && m_blocks[x][y][z-1] == 0) || y == 0)
            {
                /* std::cout << "breakfast\n"; */
                std::array<vertex, 6> face = Face(BlockFace::SOUTH, x, y, z);
                m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face), end(face));
            }

            if ((z < CH_DEPTH && m_blocks[x][y][z+1] == 0) || z == CH_DEPTH)
            {
                /* std::cout << "breakfast\n"; */
                std::array<vertex, 6> face = Face(BlockFace::NORTH, x, y, z);
                m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face), end(face));
            }
        }
      }
    }
  }
  std::cout << m_chunk_vertices.size() << "\n";
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, m_chunk_vertices.size() * sizeof(vertex), &m_chunk_vertices[0], GL_STATIC_DRAW);
}
