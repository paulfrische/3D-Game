#include <array>

#include "block.hpp"
#include "vertex.hpp"

inline std::array<vertex, 6> Face(BlockFace face) {
  // TODO: generate/return right faces/vertex arrays
  switch (face) {
  case BlockFace::TOP:
    break;
  case BlockFace::BOTTOM:
    break;
  case BlockFace::NORTH:
    break;
  case BlockFace::SOUTH:
    break;
  case BlockFace::EAST:
    break;
  case BlockFace::WEST:
    break;
  }
}
