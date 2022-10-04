#pragma once

#include <vector>

#include "chunk.hpp"

class Chunk;

class World
{
  public:
    World(unsigned int shader);

    void setBlock(unsigned int x, unsigned int y, unsigned int z, unsigned char block);

    unsigned char getBlock(unsigned int x, unsigned int y, unsigned int z);

    void generate();
    void render();

  private:
    unsigned int m_shader = 0;

    std::vector<std::vector<Chunk>> m_chunks {};
};
