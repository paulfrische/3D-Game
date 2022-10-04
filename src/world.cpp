#include <iostream>

#include <algorithm>

#include "chunk.hpp"
#include "world.hpp"
#include "config.h"

World::World(unsigned int shader)
{
  m_shader = shader;
}

void World::setBlock(unsigned int x, unsigned y, unsigned z, unsigned char block)
{
  unsigned int x_chunk = x / CH_WIDTH;
  unsigned int y_chunk = z / CH_DEPTH;

  unsigned int in_chunk_x = x % CH_WIDTH;
  unsigned int in_chunk_y = y;
  unsigned int in_chunk_z = z % CH_DEPTH;

  m_chunks.at(x_chunk).at(y_chunk).setBlock(in_chunk_x, in_chunk_y, in_chunk_z, block);
}

unsigned char World::getBlock(unsigned int x, unsigned int y, unsigned int z)
{
  // TODO: add boundary checks
  unsigned int x_chunk = x / CH_WIDTH;
  unsigned int y_chunk = z / CH_DEPTH;

  unsigned int in_chunk_x = x % CH_WIDTH;
  unsigned int in_chunk_y = y;
  unsigned int in_chunk_z = z % CH_DEPTH;

  if (x_chunk >= m_chunks.size())
  {
    return 0;
  }

  std::vector<Chunk> x_chunks = m_chunks.at(x_chunk);

  /* if (x >= x_chunks.size()) */
  /*   return 0; */

  return x_chunks.at(y_chunk).getBlock(in_chunk_x, in_chunk_y, in_chunk_z);
}

void World::generate()
{
  std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
             CH_WIDTH>
      blocks{};
  for (int x = 0; x < CH_WIDTH; x++) {
    for (int y = 0; y < CH_HEIGHT; y++) {
      for (int z = 0; z < CH_DEPTH; z++) {
        blocks[x][y][z] = 1;
      }
    }
  }

  for (int x = 0; x < 10; x++)
  {
    std::vector<Chunk> chunk_row {};
    for (int y = 0; y < 10; y++)
    {
      std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>,
             CH_WIDTH>
      chunk_blocks {};
      std::copy_n(blocks.begin(), blocks.size(), chunk_blocks.begin());
      Chunk ch = Chunk(chunk_blocks, x, y, m_shader);
      ch.genVBO(this);
      chunk_row.push_back(ch);
    }
    m_chunks.push_back(chunk_row);
  }
}

void World::render()
{
  for (std::vector<Chunk> chunks : m_chunks )
  {
    for (Chunk ch : chunks)
    {
      ch.render();
    }
  }
}
