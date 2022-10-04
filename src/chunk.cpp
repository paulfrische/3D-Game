// (modern) OpenGL
#include <GL/glew.h>

#include <array>
#include <iostream>
#include <vector>

#include "block.hpp"
#include "chunk.hpp"
#include "config.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/trigonometric.hpp>

Chunk::Chunk(
    std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
               CH_WIDTH>
        blocks,
    unsigned int x, unsigned int y, unsigned int shader) {
  m_blocks = blocks;
  m_x = x;
  m_y = y;
  m_shader = shader;
  m_model_matrix_location = glGetUniformLocation(m_shader, "model");

  m_model_matrix = glm::mat4(1.0f);
  m_model_matrix = glm::translate(m_model_matrix, glm::vec3((float)(m_x * CH_WIDTH), 0.0f, (float)(m_y * CH_DEPTH)));
}

void Chunk::render() {
  std::cout << "RENDER\n";
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glUniformMatrix4fv(m_model_matrix_location, 1, GL_FALSE, glm::value_ptr(m_model_matrix));
  glDrawArrays(GL_TRIANGLES, 0, m_chunk_vertices.size());
}

void Chunk::setBlock(unsigned int x, unsigned int y, unsigned int z,
                     unsigned char block) {
  m_blocks[x][y][z] = block;
}

unsigned char Chunk::getBlock(unsigned int x, unsigned int y, unsigned z)
{
  return m_blocks[x][y][z];
}

void Chunk::genVBO(World *world) {
  glGenBuffers(1, &m_vbo);
  m_chunk_vertices.clear();
  for (int x = 0; x < CH_WIDTH; x++) {
    for (int y = 0; y < CH_HEIGHT; y++) {
      for (int z = 0; z < CH_DEPTH; z++) {
        unsigned char block = m_blocks[x][y][z];
        if (block != 0) {
          /* if ((x > 0 && m_blocks[x - 1][y][z] == 0) || x == 0) { */
          if (x == 0 || world->getBlock(x - 1, y, z) == 0) {
            std::array<vertex, 6> face = Face(BlockFace::EAST, x, y, z);
            m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face),
                                    end(face));
          }

          if (world->getBlock(x + 1, y, z)) {
            std::array<vertex, 6> face = Face(BlockFace::WEST, x, y, z);
            m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face),
                                    end(face));
          }

          if ((y > 0 && m_blocks[x][y - 1][z] == 0) || y == 0) {
            std::array<vertex, 6> face = Face(BlockFace::BOTTOM, x, y, z);
            m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face),
                                    end(face));
          }

          if ((y < CH_HEIGHT && m_blocks[x][y + 1][z] == 0) || y == CH_HEIGHT-1) {
            std::array<vertex, 6> face = Face(BlockFace::TOP, x, y, z);
            m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face),
                                    end(face));
          }

          if ((z > 0 && m_blocks[x][y][z - 1] == 0) || z == 0) {
            std::array<vertex, 6> face = Face(BlockFace::SOUTH, x, y, z);
            m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face),
                                    end(face));
          }

          if ((z < CH_DEPTH && m_blocks[x][y][z + 1] == 0) || z == CH_DEPTH-1) {
            std::array<vertex, 6> face = Face(BlockFace::NORTH, x, y, z);
            m_chunk_vertices.insert(m_chunk_vertices.end(), begin(face),
                                    end(face));
          }
        }
      }
    }
  }
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, m_chunk_vertices.size() * sizeof(vertex),
               &m_chunk_vertices[0], GL_STATIC_DRAW);
}
