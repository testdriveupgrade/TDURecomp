project("reblue")

if (WIN32)
    option(UNLEASHED_RECOMP_D3D12 "Add D3D12 support for rendering" ON)
endif()

add_compile_options(
    -fno-strict-aliasing
    -Wno-switch
    -Wno-unused-function
    -Wno-unused-variable
    -Wno-unused-but-set-variable
    -Wno-void-pointer-to-int-cast
    -Wno-int-to-void-pointer-cast
    -Wno-invalid-offsetof
    -Wno-null-arithmetic
    -Wno-null-conversion
    -Wno-tautological-undefined-compare
)

if (WIN32)
    add_compile_options(/fp:strict)
else()
    add_compile_options(-ffp-model=strict)
endif()

add_compile_definitions(
    SDL_MAIN_HANDLED
    _DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR # Microsoft wtf?
    _CRT_SECURE_NO_WARNINGS)

set(REBLUE_PRECOMPILED_HEADERS
    "stdafx.h"
)

set(REBLUE_KERNEL_CXX_SOURCES
    "kernel/imports.cpp"
    "kernel/kernel.cpp"
    "kernel/hal.cpp"
    "kernel/obj/guest_heap.cpp"
    "kernel/obj/guest_memory.cpp"
    "kernel/xam.cpp"
    "kernel/io/file_system.cpp"
    "kernel/net.cpp"
    "kernel/obj/event.cpp"
    "kernel/obj/mutant.cpp"
    "kernel/obj/semaphore.cpp"
)

set(REBLUE_LOCALE_CXX_SOURCES
    "locale/config_locale.cpp"
    "locale/locale.cpp"
)

if (WIN32)
    set(REBLUE_OS_CXX_SOURCES
        "os/win32/logger_win32.cpp"
        "os/win32/media_win32.cpp"
        "os/win32/process_win32.cpp"
        "os/win32/user_win32.cpp"
        "os/win32/version_win32.cpp"
    )
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(REBLUE_OS_CXX_SOURCES
        "os/linux/logger_linux.cpp"
        "os/linux/media_linux.cpp"
        "os/linux/process_linux.cpp"
        "os/linux/user_linux.cpp"
        "os/linux/version_linux.cpp"
    )
endif()

set(REBLUE_CPU_CXX_SOURCES
    "cpu/guest_thread.cpp"
)

set(REBLUE_GPU_CXX_SOURCES
    "gpu/video.cpp"
    "gpu/imgui/imgui_common.cpp"
    "gpu/imgui/imgui_font_builder.cpp"
    "gpu/imgui/imgui_snapshot.cpp"
    "gpu/rhi/plume_vulkan.cpp"
)

if (UNLEASHED_RECOMP_D3D12)
   list(APPEND REBLUE_GPU_CXX_SOURCES
       "gpu/rhi/plume_d3d12.cpp"
   )
endif()

set(REBLUE_APU_CXX_SOURCES
    "apu/audio.cpp"
    #"apu/embedded_player.cpp"
    "apu/driver/sdl2_driver.cpp"
)

set(REBLUE_HID_CXX_SOURCES
    "hid/hid.cpp"
    "hid/driver/sdl_hid.cpp"
)

set(REBLUE_UI_CXX_SOURCES
#    "ui/achievement_menu.cpp"
#    "ui/achievement_overlay.cpp"
#    "ui/black_bar.cpp"
#    "ui/button_guide.cpp"
#    "ui/fader.cpp"
    "ui/game_window.cpp"
    "ui/imgui_utils.cpp"
#    "ui/installer_wizard.cpp"
#    "ui/message_window.cpp"
#    "ui/options_menu.cpp"
#    "ui/options_menu_thumbnails.cpp"
#    "ui/tv_static.cpp"
)

set(REBLUE_INSTALL_CXX_SOURCES
    "install/installer.cpp"
    "install/iso_file_system.cpp"
    "install/update_checker.cpp"
    "install/xcontent_file_system.cpp"
    "install/hashes/apotos_shamar.cpp"
    "install/hashes/chunnan.cpp"
    "install/hashes/empire_city_adabat.cpp"
    "install/hashes/game.cpp"
    "install/hashes/holoska.cpp"
    "install/hashes/mazuri.cpp"
    "install/hashes/spagonia.cpp"
    "install/hashes/update.cpp"
)

set(REBLUE_USER_CXX_SOURCES
    "user/achievement_data.cpp"
    #"user/achievement_manager.cpp"
    "user/config.cpp"
    "user/registry.cpp"
    "user/paths.cpp"
    "user/persistent_data.cpp"
    "user/persistent_storage_manager.cpp"
)

set(REBLUE_MOD_CXX_SOURCES
    "mod/mod_loader.cpp"
)

set(REBLUE_THIRDPARTY_SOURCES
    "${REBLUE_THIRDPARTY_ROOT}/imgui/backends/imgui_impl_sdl2.cpp"
    "${REBLUE_THIRDPARTY_ROOT}/imgui/imgui.cpp"
    "${REBLUE_THIRDPARTY_ROOT}/imgui/imgui_demo.cpp"
    "${REBLUE_THIRDPARTY_ROOT}/imgui/imgui_draw.cpp"
    "${REBLUE_THIRDPARTY_ROOT}/imgui/imgui_tables.cpp"
    "${REBLUE_THIRDPARTY_ROOT}/imgui/imgui_widgets.cpp"
    "${REBLUE_THIRDPARTY_ROOT}/implot/implot.cpp"
    "${REBLUE_THIRDPARTY_ROOT}/implot/implot_demo.cpp"
    "${REBLUE_THIRDPARTY_ROOT}/implot/implot_items.cpp"
    "${REBLUE_TOOLS_ROOT}/XenosRecomp/thirdparty/smol-v/source/smolv.cpp"
)

set(REBLUE_THIRDPARTY_INCLUDES
    "${REBLUE_THIRDPARTY_ROOT}/concurrentqueue"
    "${REBLUE_THIRDPARTY_ROOT}/ddspp"
    "${REBLUE_THIRDPARTY_ROOT}/imgui"
    "${REBLUE_THIRDPARTY_ROOT}/implot"
    "${REBLUE_THIRDPARTY_ROOT}/json/include"
    "${REBLUE_THIRDPARTY_ROOT}/magic_enum/include"
    "${REBLUE_THIRDPARTY_ROOT}/stb"
    "${REBLUE_THIRDPARTY_ROOT}/unordered_dense/include"
    "${REBLUE_THIRDPARTY_ROOT}/volk"
    "${REBLUE_THIRDPARTY_ROOT}/Vulkan-Headers/include"
    "${REBLUE_THIRDPARTY_ROOT}/VulkanMemoryAllocator/include"
    "${REBLUE_TOOLS_ROOT}/bc_diff"
    "${REBLUE_TOOLS_ROOT}/XenosRecomp/thirdparty/smol-v/source"
)

if (UNLEASHED_RECOMP_D3D12)
    list(APPEND REBLUE_THIRDPARTY_INCLUDES "${REBLUE_THIRDPARTY_ROOT}/D3D12MemoryAllocator/include")
    list(APPEND REBLUE_THIRDPARTY_SOURCES "${REBLUE_THIRDPARTY_ROOT}/D3D12MemoryAllocator/src/D3D12MemAlloc.cpp")
endif()

set_source_files_properties(${REBLUE_THIRDPARTY_SOURCES} PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

set(REBLUE_CXX_SOURCES
    "app.cpp"
    "exports.cpp"
    "main.cpp"
    "misc_impl.cpp"
    "preload_executable.cpp"
    "sdl_listener.cpp"
    "stdafx.cpp"
    "version.cpp"
    
    ${REBLUE_KERNEL_CXX_SOURCES}
    ${REBLUE_LOCALE_CXX_SOURCES}
    ${REBLUE_OS_CXX_SOURCES}
    ${REBLUE_CPU_CXX_SOURCES}
    ${REBLUE_GPU_CXX_SOURCES}
    ${REBLUE_APU_CXX_SOURCES}
    ${REBLUE_HID_CXX_SOURCES}
    ${REBLUE_UI_CXX_SOURCES}
#   ${REBLUE_INSTALL_CXX_SOURCES}
    ${REBLUE_USER_CXX_SOURCES}
#   ${REBLUE_MOD_CXX_SOURCES}
    ${REBLUE_THIRDPARTY_SOURCES}
)

include("version.cmake")

set(VERSION_TXT "${PROJECT_SOURCE_DIR}/res/version.txt")

# Only show Git info and build type if not Release.
set(SHOW_GIT_INFO_AND_BUILD_TYPE 0)
if (NOT ${CMAKE_BUILD_TYPE} MATCHES "Release")
    set(SHOW_GIT_INFO_AND_BUILD_TYPE 1)
endif()

GenerateVersionSources(
    OUTPUT_DIR ${PROJECT_SOURCE_DIR}
    VERSION_TXT ${VERSION_TXT}
    H_TEMPLATE "${PROJECT_SOURCE_DIR}/res/version.h.template"
    CXX_TEMPLATE "${PROJECT_SOURCE_DIR}/res/version.cpp.template"
    BUILD_TYPE ${CMAKE_BUILD_TYPE}
    SHOW_GIT_INFO ${SHOW_GIT_INFO_AND_BUILD_TYPE}
    SHOW_BUILD_TYPE ${SHOW_GIT_INFO_AND_BUILD_TYPE}
)

if (WIN32)
    # Create binary version number for Win32 integer attributes.
    CreateVersionString(
        VERSION_TXT ${VERSION_TXT}
        OUTPUT_CSV 1
        OUTPUT_VAR WIN32_VERSION_BINARY
    )

    # Create string version number for Win32 detailed attributes.
    CreateVersionString(
        VERSION_TXT ${VERSION_TXT}
        BUILD_TYPE ${CMAKE_BUILD_TYPE}
        SHOW_GIT_INFO ${SHOW_GIT_INFO_AND_BUILD_TYPE}
        SHOW_BUILD_TYPE ${SHOW_GIT_INFO_AND_BUILD_TYPE}
        OUTPUT_VAR WIN32_VERSION_STRING
    )

    # Set Win32 icon path.
    set(WIN32_ICON_PATH "${PROJECT_SOURCE_DIR}/../resources/images/reblue.ico")

    configure_file("res/win32/res.rc.template" "${CMAKE_BINARY_DIR}/res.rc" @ONLY)
    add_executable(reblue ${REBLUE_CXX_SOURCES} "${CMAKE_BINARY_DIR}/res.rc")

    # Hide console for release configurations.
    if (${CMAKE_BUILD_TYPE} MATCHES "Release")
        target_link_options(reblue PRIVATE "/SUBSYSTEM:WINDOWS" "/ENTRY:mainCRTStartup")
    endif()
else()
    add_executable(reblue ${REBLUE_CXX_SOURCES})
endif()


if (UNLEASHED_RECOMP_D3D12)
    find_package(directx-headers CONFIG REQUIRED)
    find_package(directx12-agility CONFIG REQUIRED)
    target_compile_definitions(reblue PRIVATE 
        UNLEASHED_RECOMP_D3D12
        D3D12MA_USING_DIRECTX_HEADERS
        D3D12MA_OPTIONS16_SUPPORTED
    )
endif()


if (NOT TARGET Microsoft::DirectXShaderCompiler)
    find_package(directx-dxc REQUIRED)
endif()
find_package(CURL REQUIRED)

if (UNLEASHED_RECOMP_D3D12)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/D3D12)
    add_custom_command(TARGET reblue POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_PROPERTY:Microsoft::DirectX12-Core,IMPORTED_LOCATION_RELEASE> ${CMAKE_CURRENT_BINARY_DIR}/D3D12
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_PROPERTY:Microsoft::DirectX12-Layers,IMPORTED_LOCATION_DEBUG> ${CMAKE_CURRENT_BINARY_DIR}/D3D12
       COMMAND_EXPAND_LISTS
    )
    
    find_file(DIRECTX_DXIL_LIBRARY "dxil.dll")
    file(COPY ${DIRECTX_DXIL_LIBRARY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

    target_link_libraries(reblue PRIVATE
        Microsoft::DirectX-Headers 
        Microsoft::DirectX-Guids 
        Microsoft::DirectX12-Agility
        Microsoft::DirectXShaderCompiler
        Microsoft::DXIL
        dxgi
    )
endif()

file(CHMOD ${DIRECTX_DXC_TOOL} PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE)

if (WIN32)
    target_link_libraries(reblue PRIVATE
        comctl32
        dwmapi
        ntdll
        Shcore
        Synchronization
        winmm
    )
endif()

target_link_libraries(reblue PRIVATE
    fmt::fmt
    libzstd_static
    msdf-atlas-gen::msdf-atlas-gen
    nfd::nfd
    o1heap
    XenonUtils
    SDL2::SDL2-static
    SDL2_mixer
    tomlplusplus::tomlplusplus
    rebluelib
    xxHash::xxhash
    CURL::libcurl
)

target_include_directories(reblue PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${REBLUE_THIRDPARTY_INCLUDES}
)

target_precompile_headers(reblue PUBLIC ${REBLUE_PRECOMPILED_HEADERS})

function(BIN2C)
    cmake_parse_arguments(BIN2C_ARGS "" "TARGET_OBJ;SOURCE_FILE;DEST_FILE;ARRAY_NAME;COMPRESSION_TYPE" "" ${ARGN})

    if(NOT BIN2C_ARGS_TARGET_OBJ)
        message(FATAL_ERROR "TARGET_OBJ not specified.")
    endif()

    if(NOT BIN2C_ARGS_SOURCE_FILE)
        message(FATAL_ERROR "SOURCE_FILE not specified.")
    endif()

    if(NOT BIN2C_ARGS_DEST_FILE)
        set(BIN2C_ARGS_DEST_FILE "${BIN2C_ARGS_SOURCE_FILE}")
    endif()

    if(NOT BIN2C_ARGS_COMPRESSION_TYPE)
        set(BIN2C_ARGS_COMPRESSION_TYPE "none")
    endif()

    add_custom_command(OUTPUT "${BIN2C_ARGS_DEST_FILE}.c"
        COMMAND $<TARGET_FILE:file_to_c> "${BIN2C_ARGS_SOURCE_FILE}" "${BIN2C_ARGS_ARRAY_NAME}" "${BIN2C_ARGS_COMPRESSION_TYPE}" "${BIN2C_ARGS_DEST_FILE}.c" "${BIN2C_ARGS_DEST_FILE}.h"
        DEPENDS "${BIN2C_ARGS_SOURCE_FILE}"
        BYPRODUCTS "${BIN2C_ARGS_DEST_FILE}.h"
        COMMENT "Generating binary header for ${BIN2C_ARGS_SOURCE_FILE}..."
    )

    set_source_files_properties(${BIN2C_ARGS_DEST_FILE}.c PROPERTIES SKIP_PRECOMPILE_HEADERS ON)
    target_sources(${BIN2C_ARGS_TARGET_OBJ} PRIVATE ${BIN2C_ARGS_DEST_FILE}.c)
endfunction()

set(RESOURCES_SOURCE_PATH "${PROJECT_SOURCE_DIR}/../resources")
set(RESOURCES_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/res")

## Miscellaneous ##
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/bc_diff/button_bc_diff.bin" DEST_FILE "${RESOURCES_OUTPUT_PATH}/bc_diff/button_bc_diff.bin" ARRAY_NAME "g_button_bc_diff" COMPRESSION_TYPE "zstd")
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/font/im_font_atlas.bin" DEST_FILE "${RESOURCES_OUTPUT_PATH}/font/im_font_atlas.bin" ARRAY_NAME "g_im_font_atlas" COMPRESSION_TYPE "zstd")
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/font/im_font_atlas.dds" DEST_FILE "${RESOURCES_OUTPUT_PATH}/font/im_font_atlas.dds" ARRAY_NAME "g_im_font_atlas_texture" COMPRESSION_TYPE "zstd")
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/images/achievements_menu/trophy.dds" DEST_FILE "${RESOURCES_OUTPUT_PATH}/images/achievements_menu/trophy.dds" ARRAY_NAME "g_trophy" COMPRESSION_TYPE "zstd")
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/images/common/controller.dds" DEST_FILE "${RESOURCES_OUTPUT_PATH}/images/common/controller.dds" ARRAY_NAME "g_controller" COMPRESSION_TYPE "zstd")
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/images/common/general_window.dds" DEST_FILE "${RESOURCES_OUTPUT_PATH}/images/common/general_window.dds" ARRAY_NAME "g_general_window" COMPRESSION_TYPE "zstd")
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/images/common/hedge-dev.dds" DEST_FILE "${RESOURCES_OUTPUT_PATH}/images/common/hedge-dev.dds" ARRAY_NAME "g_hedgedev" COMPRESSION_TYPE "zstd")
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/images/common/kbm.dds" DEST_FILE "${RESOURCES_OUTPUT_PATH}/images/common/kbm.dds" ARRAY_NAME "g_kbm" COMPRESSION_TYPE "zstd")
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/images/common/select.dds" DEST_FILE "${RESOURCES_OUTPUT_PATH}/images/common/select.dds" ARRAY_NAME "g_select" COMPRESSION_TYPE "zstd")
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/images/common/light.dds" DEST_FILE "${RESOURCES_OUTPUT_PATH}/images/common/light.dds" ARRAY_NAME "g_light" COMPRESSION_TYPE "zstd")
## Game Icon ##
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/images/game_icon.bmp" DEST_FILE "${RESOURCES_OUTPUT_PATH}/images/game_icon.bmp" ARRAY_NAME "g_game_icon")
BIN2C(TARGET_OBJ reblue SOURCE_FILE "${RESOURCES_SOURCE_PATH}/images/game_icon_night.bmp" DEST_FILE "${RESOURCES_OUTPUT_PATH}/images/game_icon_night.bmp" ARRAY_NAME "g_game_icon_night")


function(compile_shader FILE_PATH TARGET_NAME)
    set(FILE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/gpu/shader/${FILE_PATH}.hlsl)
    cmake_path(GET FILE_PATH STEM VARIABLE_NAME)
    if (UNLEASHED_RECOMP_D3D12)
        add_custom_command(
            OUTPUT ${FILE_PATH}.dxil.h
            COMMAND ${DIRECTX_DXC_TOOL} -T ${TARGET_NAME} -HV 2021 -all-resources-bound -Wno-ignored-attributes -Fh ${FILE_PATH}.dxil.h ${FILE_PATH} -Vn g_${VARIABLE_NAME}_dxil
            DEPENDS ${FILE_PATH}
        )
        target_sources(reblue PRIVATE ${FILE_PATH}.dxil.h)
    endif()
    add_custom_command(
        OUTPUT ${FILE_PATH}.spirv.h
        COMMAND ${DIRECTX_DXC_TOOL} -T ${TARGET_NAME} -HV 2021 -all-resources-bound -spirv -fvk-use-dx-layout ${ARGN} -Fh ${FILE_PATH}.spirv.h ${FILE_PATH} -Vn g_${VARIABLE_NAME}_spirv
        DEPENDS ${FILE_PATH}
    )
    target_sources(reblue PRIVATE ${FILE_PATH}.spirv.h)
endfunction()

function(compile_vertex_shader FILE_PATH)
    compile_shader(${FILE_PATH} vs_6_0 -fvk-invert-y)
endfunction()

function(compile_pixel_shader FILE_PATH)
    compile_shader(${FILE_PATH} ps_6_0)
endfunction()

compile_pixel_shader(blend_color_alpha_ps)
compile_vertex_shader(copy_vs)
compile_pixel_shader(copy_color_ps)
compile_pixel_shader(copy_depth_ps)
compile_pixel_shader(csd_filter_ps)
compile_vertex_shader(csd_no_tex_vs)
compile_vertex_shader(csd_vs)
compile_pixel_shader(enhanced_motion_blur_ps)
compile_pixel_shader(gaussian_blur_3x3)
compile_pixel_shader(gaussian_blur_5x5)
compile_pixel_shader(gaussian_blur_7x7)
compile_pixel_shader(gaussian_blur_9x9)
compile_pixel_shader(gamma_correction_ps)
compile_pixel_shader(imgui_ps)
compile_vertex_shader(imgui_vs)
compile_pixel_shader(movie_ps)
compile_vertex_shader(movie_vs)
compile_pixel_shader(resolve_msaa_color_2x)
compile_pixel_shader(resolve_msaa_color_4x)
compile_pixel_shader(resolve_msaa_color_8x)
compile_pixel_shader(resolve_msaa_depth_2x)
compile_pixel_shader(resolve_msaa_depth_4x)
compile_pixel_shader(resolve_msaa_depth_8x)
