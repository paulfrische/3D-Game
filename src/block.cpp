#include <array>

#include "block.hpp"
#include "vertex.hpp"

#define TOP_COLOR    1.0f, 1.0f, 1.0f
#define BOTTOM_COLOR 0.0f, 1.0f, 1.0f
#define NORTH_COLOR  0.0f, 1.0f, 0.0f
#define SOUTH_COLOR  0.0f, 0.0f, 1.0f
#define EAST_COLOR   1.0f, 1.0f, 0.0f
#define WEST_COLOR   1.0f, 0.0f, 0.0f

std::array<vertex, 6> Face(BlockFace face, int x, int y, int z) {
  // TODO: generate/return right faces/vertex arrays
  switch (face) {
  case BlockFace::TOP:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 1.0f + z, TOP_COLOR},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, TOP_COLOR},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, TOP_COLOR},

        vertex{0.0f + x, 1.0f + y, 0.0f + z, TOP_COLOR},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, TOP_COLOR},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, TOP_COLOR},
    }};
  case BlockFace::BOTTOM:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 0.0f + y, 1.0f + z, BOTTOM_COLOR},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, BOTTOM_COLOR},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, BOTTOM_COLOR},

        vertex{0.0f + x, 0.0f + y, 0.0f + z, BOTTOM_COLOR},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, BOTTOM_COLOR},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, BOTTOM_COLOR},
    }};
    break;
  case BlockFace::NORTH:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 1.0f + z, NORTH_COLOR},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, NORTH_COLOR},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, NORTH_COLOR},

        vertex{0.0f + x, 0.0f + y, 1.0f + z, NORTH_COLOR},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, NORTH_COLOR},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, NORTH_COLOR},
    }};
    break;
  case BlockFace::SOUTH:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 0.0f + z, SOUTH_COLOR},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, SOUTH_COLOR},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, SOUTH_COLOR},

        vertex{0.0f + x, 0.0f + y, 0.0f + z, SOUTH_COLOR},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, SOUTH_COLOR},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, SOUTH_COLOR},
    }};
    break;
  case BlockFace::EAST:
    return std::array<vertex, 6>{{
        vertex{0.0f + x, 1.0f + y, 1.0f + z, EAST_COLOR},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, EAST_COLOR},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, EAST_COLOR},

        vertex{0.0f + x, 0.0f + y, 0.0f + z, EAST_COLOR},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, EAST_COLOR},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, EAST_COLOR},
    }};
    break;
  case BlockFace::WEST:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 1.0f + z, WEST_COLOR},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, WEST_COLOR},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, WEST_COLOR},

        vertex{1.0f + x, 0.0f + y, 0.0f + z, WEST_COLOR},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, WEST_COLOR},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, WEST_COLOR},
    }};
    break;
  }
}
