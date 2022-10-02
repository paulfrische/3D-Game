#pragma once

#include <array>

// (modern) OpenGL
#include <GL/glew.h>

#include "config.h"

class Chunk {
    public:
        Chunk(std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>, CH_WIDTH> blocks, unsigned int x, unsigned int y);
        void render();
        void setBlock(unsigned int x, unsigned int y, unsigned int z, unsigned char block);

    private:
        std::array<std::array<std::array<unsigned char, CH_DEPTH>, CH_HEIGHT>, CH_WIDTH> m_blocks;

        unsigned int m_vbo;
        unsigned int m_x;
        unsigned int m_y;

        void genVBO();
};
