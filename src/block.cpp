#include <array>

#include "block.hpp"
#include "vertex.hpp"

/* #define TOP_COLOR 1.0f, 1.0f, 1.0f */
/* #define BOTTOM_COLOR 0.0f, 1.0f, 1.0f */
/* #define NORTH_COLOR 0.0f, 1.0f, 0.0f */
/* #define SOUTH_COLOR 0.0f, 0.0f, 1.0f */
/* #define EAST_COLOR 1.0f, 1.0f, 0.0f */
/* #define WEST_COLOR 1.0f, 0.0f, 0.0f */

#define TOP_COLOR 0.28f, 0.5f, 0.08f
#define BOTTOM_COLOR 0.28f, 0.5f, 0.08f
#define NORTH_COLOR 0.28f, 0.5f, 0.08f
#define SOUTH_COLOR 0.28f, 0.5f, 0.08f
#define EAST_COLOR 0.28f, 0.5f, 0.08f
#define WEST_COLOR 0.28f, 0.5f, 0.08f

std::array<vertex, 6> Face(BlockFace face, int x, int y, int z) {
  // TODO: generate/return right faces/vertex arrays
  switch (face) {
  case BlockFace::TOP:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 1.0f + z, TOP_COLOR, 0.0f, 1.0f, 0.0f},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, TOP_COLOR, 0.0f, 1.0f, 0.0f},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, TOP_COLOR, 0.0f, 1.0f, 0.0f},

        vertex{0.0f + x, 1.0f + y, 0.0f + z, TOP_COLOR, 0.0f, 1.0f, 0.0f},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, TOP_COLOR, 0.0f, 1.0f, 0.0f},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, TOP_COLOR, 0.0f, 1.0f, 0.0f},
    }};
  case BlockFace::BOTTOM:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 0.0f + y, 1.0f + z, BOTTOM_COLOR, 0.0f, -1.0f, 0.0f},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, BOTTOM_COLOR, 0.0f, -1.0f, 0.0f},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, BOTTOM_COLOR, 0.0f, -1.0f, 0.0f},

        vertex{0.0f + x, 0.0f + y, 0.0f + z, BOTTOM_COLOR, 0.0f, -1.0f, 0.0f},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, BOTTOM_COLOR, 0.0f, -1.0f, 0.0f},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, BOTTOM_COLOR, 0.0f, -1.0f, 0.0f},
    }};
    break;
  case BlockFace::NORTH:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 1.0f + z, NORTH_COLOR, 0.0f, 0.0f, 1.0f},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, NORTH_COLOR, 0.0f, 0.0f, 1.0f},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, NORTH_COLOR, 0.0f, 0.0f, 1.0f},

        vertex{0.0f + x, 0.0f + y, 1.0f + z, NORTH_COLOR, 0.0f, 0.0f, 1.0f},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, NORTH_COLOR, 0.0f, 0.0f, 1.0f},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, NORTH_COLOR, 0.0f, 0.0f, 1.0f},
    }};
    break;
  case BlockFace::SOUTH:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 0.0f + z, SOUTH_COLOR, 0.0f, 0.0f, -1.0f},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, SOUTH_COLOR, 0.0f, 0.0f, -1.0f},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, SOUTH_COLOR, 0.0f, 0.0f, -1.0f},

        vertex{0.0f + x, 0.0f + y, 0.0f + z, SOUTH_COLOR, 0.0f, 0.0f, -1.0f},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, SOUTH_COLOR, 0.0f, 0.0f, -1.0f},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, SOUTH_COLOR, 0.0f, 0.0f, -1.0f},
    }};
    break;
  case BlockFace::EAST:
    return std::array<vertex, 6>{{
        vertex{0.0f + x, 1.0f + y, 1.0f + z, EAST_COLOR, -1.0f, 0.0f, 0.0f},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, EAST_COLOR, -1.0f, 0.0f, 0.0f},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, EAST_COLOR, -1.0f, 0.0f, 0.0f},

        vertex{0.0f + x, 0.0f + y, 0.0f + z, EAST_COLOR, -1.0f, 0.0f, 0.0f},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, EAST_COLOR, -1.0f, 0.0f, 0.0f},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, EAST_COLOR, -1.0f, 0.0f, 0.0f},
    }};
    break;
  case BlockFace::WEST:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 1.0f + z, WEST_COLOR, 1.0f, 0.0f, 0.0f},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, WEST_COLOR, 1.0f, 0.0f, 0.0f},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, WEST_COLOR, 1.0f, 0.0f, 0.0f},

        vertex{1.0f + x, 0.0f + y, 0.0f + z, WEST_COLOR, 1.0f, 0.0f, 0.0f},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, WEST_COLOR, 1.0f, 0.0f, 0.0f},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, WEST_COLOR, 1.0f, 0.0f, 0.0f}
    }};
    break;
  }
}
