# 3D-Game

<a href="https://github.com/PythonPizzaDE/Voxel-Rust">Great Rust rewrite</a>

This should be a little Voxel game/demo.
## Compiling
To build you'll need to install premake5, glew and glfw.
To build and run(on linux):
```bash
premake5 gmake2
make config=release # for a release build
./build/Release/3D-Game
```
Good luck compiling on windows.
## TODO
- [x] basic camera
- [ ] generate block faces
  - [x] generate outer faces of chunk
  - [ ] leave faces which are on chunk border but aren't exposed
- [x] construct chunks
