#include <array>

#include "block.hpp"
#include "vertex.hpp"

std::array<vertex, 6> Face(BlockFace face, int x, int y, int z) {
  // TODO: generate/return right faces/vertex arrays
  switch (face) {
  case BlockFace::TOP:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},

        vertex{0.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
    }};
  case BlockFace::BOTTOM:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 0.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},

        vertex{0.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
    }};
    break;
  case BlockFace::NORTH:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},

        vertex{0.0f + x, 0.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 1.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
    }};
    break;
  case BlockFace::SOUTH:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},

        vertex{0.0f + x, 0.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 0.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
    }};
    break;
  case BlockFace::EAST:
    return std::array<vertex, 6>{{
        vertex{0.0f + x, 1.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},

        vertex{0.0f + x, 0.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{0.0f + x, 0.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
    }};
    break;
  case BlockFace::WEST:
    return std::array<vertex, 6>{{
        vertex{1.0f + x, 1.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},

        vertex{1.0f + x, 0.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 1.0f + y, 0.0f + z, 0.3f, 1.0f, 0.3f},
        vertex{1.0f + x, 0.0f + y, 1.0f + z, 0.3f, 1.0f, 0.3f},
    }};
    break;
  }
}
