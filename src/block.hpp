#pragma once

#include <array>

#include "vertex.hpp"

enum class BlockFace {
  TOP,
  BOTTOM,
  NORTH,
  SOUTH,
  EAST,
  WEST,
};

std::array<vertex, 6> Face(BlockFace face, int x, int y, int z);
