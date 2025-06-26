project("rebluelib")

add_compile_options(
    -fno-strict-aliasing
)

if (WIN32)
    add_compile_options(/fp:strict)
else()
    add_compile_options(-ffp-model=strict)
endif()

set(REBLUE_PPC_RECOMPILED_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/ppc/ppc_config.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/ppc/ppc_context.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/ppc/ppc_func_mapping.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ppc/ppc_recomp_shared.h"
)
set(REBLUE_CONFIG_FILE="${CMAKE_CURRENT_SOURCE_DIR}/config/config.toml")

target_compile_definitions(XenonRecomp PRIVATE 
    XENON_RECOMP_CONFIG_FILE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/config/config.toml\"
    XENON_RECOMP_HEADER_FILE_PATH=\"${REBLUE_TOOLS_ROOT}/XenonRecomp/XenonUtils/ppc_context.h\")

 foreach(i RANGE 0 74)
    list(APPEND REBLUE_PPC_RECOMPILED_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/ppc/ppc_recomp.${i}.cpp")
 endforeach()

add_custom_command(
    OUTPUT 
        ${REBLUE_PPC_RECOMPILED_SOURCES}
    COMMAND 
        $<TARGET_FILE:XenonRecomp>
    DEPENDS 
        "${CMAKE_CURRENT_SOURCE_DIR}/private/default.xex"
        "${CMAKE_CURRENT_SOURCE_DIR}/config/config.toml"
)

## Define paths for shader extraction
#set(SHADER_ARCHIVE "${CMAKE_CURRENT_SOURCE_DIR}/private/!necessity.ipk")
#set(SHADER_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/private/shaders")
#set(SHADER_EXTRACTED_FLAG "${SHADER_OUTPUT_DIR}/.extracted_marker")
#set(QUICKBMS_SCRIPT "${CMAKE_SOURCE_DIR}/scripts/bluedragon.bms")
#file(MAKE_DIRECTORY ${SHADER_OUTPUT_DIR})
#
## Extract shaders using QuickBMS
#add_custom_command(
#    OUTPUT ${SHADER_EXTRACTED_FLAG}
#    COMMAND ${QUICKBMS_EXECUTABLE} -o -f "*.pso;*.vso" ${QUICKBMS_SCRIPT} ${SHADER_ARCHIVE} ${SHADER_OUTPUT_DIR}
#    COMMAND ${CMAKE_COMMAND} -E touch ${SHADER_EXTRACTED_FLAG}
#    DEPENDS 
#        ${SHADER_ARCHIVE}
#        ${QUICKBMS_SCRIPT}
#    COMMENT "Extracting shaders from ${SHADER_ARCHIVE} using QuickBMS"
#    VERBATIM
#)
#
#add_custom_target(extract_shaders
#    DEPENDS ${SHADER_EXTRACTED_FLAG}
#)
#
#set(XENOS_RECOMP_ROOT "${REBLUE_TOOLS_ROOT}/XenosRecomp/XenosRecomp")
#set(XENOS_RECOMP_INCLUDE "${XENOS_RECOMP_ROOT}/shader_common.h")
#
#target_compile_definitions(XenosRecomp PRIVATE 
#    XENOS_RECOMP_INPUT=\"${CMAKE_CURRENT_SOURCE_DIR}/private/shaders\" 
#    XENOS_RECOMP_OUTPUT=\"${CMAKE_CURRENT_SOURCE_DIR}/shader/shader_cache.cpp\"
#    XENOS_RECOMP_INCLUDE_INPUT=\"${XENOS_RECOMP_INCLUDE}\"
#)
#
#file(GLOB XENOS_RECOMP_SOURCES 
#    "${XENOS_RECOMP_ROOT}/*.h"
#    "${XENOS_RECOMP_ROOT}/*.cpp"
#)
#
#add_custom_command(
#    OUTPUT 
#        "${CMAKE_CURRENT_SOURCE_DIR}/shader/shader_cache.cpp"
#    COMMAND
#        $<TARGET_FILE:XenosRecomp>
#    DEPENDS 
#        ${SHADER_EXTRACTED_FLAG}
#        ${XENOS_RECOMP_SOURCES} 
#        ${XENOS_RECOMP_INCLUDE}
#)

add_library(rebluelib 
    ${REBLUE_PPC_RECOMPILED_SOURCES}
    "shader/shader_cache.h"
    "shader/shader_cache.cpp"
)

target_include_directories(rebluelib 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_precompile_headers(rebluelib
    PUBLIC
        "ppc/ppc_recomp_shared.h"
)


