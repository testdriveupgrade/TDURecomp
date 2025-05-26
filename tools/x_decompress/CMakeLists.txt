project("x_decompress")
set(CMAKE_CXX_STANDARD 17)

add_executable(x_decompress
    "x_decompress.cpp"
    "${REBLUE_TOOLS_ROOT}/XenonRecomp/thirdparty/libmspack/libmspack/mspack/lzxd.c"
)

target_include_directories(x_decompress
    PRIVATE "${REBLUE_TOOLS_ROOT}/XenonRecomp/thirdparty/libmspack/libmspack/mspack"
)
