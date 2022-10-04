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
    unsigned int x, unsigned int y, unsigned int shader)
    : m_chunk_vertices() {
  m_blocks = blocks;
  m_x = x;
  m_y = y;
  m_shader = shader;
  m_model_matrix_location = glGetUniformLocation(m_shader, "model");

  m_model_matrix = glm::mat4(1.0f);
  m_model_matrix =
      glm::translate(m_model_matrix, glm::vec3((float)(m_x * CH_WIDTH), 0.0f,
                                               (float)(m_y * CH_DEPTH)));
}

void Chunk::render() {
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glUniformMatrix4fv(m_model_matrix_location, 1, GL_FALSE,
                     glm::value_ptr(m_model_matrix));
  glDrawArrays(GL_TRIANGLES, 0, m_chunk_vertices.size());
}

void Chunk::setBlock(unsigned int x, unsigned int y, unsigned int z,
                     unsigned char block) {
  m_blocks[x][y][z] = block;
}

unsigned char Chunk::getBlock(unsigned int x, unsigned int y, unsigned z) {
  return m_blocks[x][y][z];
}

ChunkManager::ChunkManager(unsigned int shader) { m_shader = shader; }

void ChunkManager::genVBOs() {
  for (int chunk_x = 0; chunk_x < m_chunks.size(); chunk_x++) {
    for (int chunk_y = 0; chunk_y < m_chunks.at(chunk_x).size(); chunk_y++) {
      Chunk *chunk = m_chunks.at(chunk_x).at(chunk_y);
      glGenBuffers(1, &(chunk->m_vbo));
      chunk->m_chunk_vertices.clear();
      for (int x = 0; x < CH_WIDTH; x++) {
        for (int y = 0; y < CH_HEIGHT; y++) {
          for (int z = 0; z < CH_DEPTH; z++) {

            unsigned char block = chunk->m_blocks[x][y][z];

            if (block != 0) {
              if (x == 0 || chunk->m_blocks[x - 1][y][z] == 0) {
                std::array<vertex, 6> face = Face(BlockFace::EAST, x, y, z);
                chunk->m_chunk_vertices.insert(chunk->m_chunk_vertices.end(),
                                               begin(face), end(face));
              }

              if (x == CH_WIDTH - 1 ||
                  x < CH_WIDTH && chunk->m_blocks[x + 1][y][z] == 0) {
                std::array<vertex, 6> face = Face(BlockFace::WEST, x, y, z);
                chunk->m_chunk_vertices.insert(chunk->m_chunk_vertices.end(),
                                               begin(face), end(face));
              }

              if (y == 0 || chunk->m_blocks[x][y - 1][z] == 0) {
                std::array<vertex, 6> face = Face(BlockFace::BOTTOM, x, y, z);
                chunk->m_chunk_vertices.insert(chunk->m_chunk_vertices.end(),
                                               begin(face), end(face));
              }

              if (y == CH_HEIGHT - 1 || chunk->m_blocks[x][y + 1][z] == 0) {
                std::array<vertex, 6> face = Face(BlockFace::TOP, x, y, z);
                chunk->m_chunk_vertices.insert(chunk->m_chunk_vertices.end(),
                                               begin(face), end(face));
              }

              if (z == 0 || chunk->m_blocks[x][y][z - 1] == 0) {
                std::array<vertex, 6> face = Face(BlockFace::SOUTH, x, y, z);
                chunk->m_chunk_vertices.insert(chunk->m_chunk_vertices.end(),
                                               begin(face), end(face));
              }

              if (z == CH_DEPTH - 1 || chunk->m_blocks[x][y][z + 1] == 0) {
                std::array<vertex, 6> face = Face(BlockFace::NORTH, x, y, z);
                chunk->m_chunk_vertices.insert(chunk->m_chunk_vertices.end(),
                                               begin(face), end(face));
              }
            }
          }
        }
      }
      glBindBuffer(GL_ARRAY_BUFFER, chunk->m_vbo);
      glBufferData(GL_ARRAY_BUFFER,
                   chunk->m_chunk_vertices.size() * sizeof(vertex),
                   &(chunk->m_chunk_vertices[0]), GL_STATIC_DRAW);
    }
  }
}

void ChunkManager::render() {
  for (int x = 0; x < m_chunks.size(); x++) {
    for (int y = 0; y < m_chunks.at(x).size(); y++) {
      m_chunks.at(x).at(y)->render();
    }
  }
}

void ChunkManager::generateWorld() {
  std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
             CH_WIDTH>
      blocks;
  for (int x = 0; x < CH_WIDTH; x++) {
    for (int y = 0; y < CH_HEIGHT; y++) {
      for (int z = 0; z < CH_DEPTH; z++) {
        srand(time(0));
        if (rand() % 2 == 0)
          blocks[x][y][z] = 1;
      }
    }
  }
  for (int x = 0; x < 10; x++) {
    std::vector<Chunk *> chunks{};
    for (int y = 0; y < 10; y++) {
      Chunk *ch = new Chunk(blocks, x, y, m_shader);
      chunks.push_back(ch);
    }
    m_chunks.push_back(chunks);
  }
}

ChunkManager::~ChunkManager() {
  for (auto chunks : m_chunks) {
    for (Chunk *ch : chunks) {
      delete ch;
    }
  }
}
