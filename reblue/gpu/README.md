# GPU module

This directory contains the graphics subsystem.

## Recent changes
- Added `gpu_stub.cpp` with simple stub implementations for `LoadTexture`, `AddImGuiCallback`, and `ResetImGuiCallbacks` so that the project builds without the full GPU backend.
- Restored some shader include statements and pipeline logic in `video.cpp` to allow compilation.

## Next steps
1. Replace the stubs with real GPU code and re-enable the GPU sources in `reblue/CMakeLists.txt`.
2. Ensure required graphics libraries and drivers are available before running the game.
