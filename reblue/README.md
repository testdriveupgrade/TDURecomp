# Reblue

This folder holds the main source files for the `reblue` executable.

## Recent changes
- Added `gpu/gpu_stub.cpp` with placeholder GPU functions so the project links even when the GPU module is disabled.
- Updated `CMakeLists.txt` to compile the stub and skip the full GPU sources.

## Next steps
1. Install the vcpkg dependencies and Ninja to satisfy `CMakePresets.json`.
2. Implement real GPU, APU, and CPU backends and enable their source lists in `CMakeLists.txt`.
