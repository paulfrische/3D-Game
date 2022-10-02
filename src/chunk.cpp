// (modern) OpenGL
#include <GL/glew.h>

#include <array>

#include "chunk.hpp"
#include "config.h"

Chunk::Chunk(std::array<
             std::array<
             std::array<unsigned char, CH_DEPTH>,
             CH_HEIGHT>,
             CH_WIDTH> blocks,
             unsigned int x, unsigned int y)
{
    m_blocks = blocks;
    m_x = x;
    m_y = y;
}

void Chunk::render()
{
}

inline void Chunk::setBlock(unsigned int x, unsigned int y, unsigned int z, unsigned char block)
{
    m_blocks[x][y][z] = block;
}

void Chunk::genVBO()
{
    glGenBuffers(1, &m_vbo);
    for (int x = 0; x < CH_WIDTH; x++)
    {
        for (int y = 0; y < CH_HEIGHT; y++)
        {
            for (int z = 0; z < CH_DEPTH; z++)
            {
                unsigned char block = m_blocks[x][y][z];
                if (block != 0)
                {
                    // TODO: add block buffer logic thingy
                }
            }
        }
    }
}
