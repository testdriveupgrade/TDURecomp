add_subdirectory(${REBLUE_TOOLS_ROOT}/bc_diff)
add_subdirectory(${REBLUE_TOOLS_ROOT}/file_to_c)
add_subdirectory(${REBLUE_TOOLS_ROOT}/fshasher)
add_subdirectory(${REBLUE_TOOLS_ROOT}/x_decompress)
add_subdirectory(${REBLUE_TOOLS_ROOT}/XenonRecomp)
add_subdirectory(${REBLUE_TOOLS_ROOT}/XenosRecomp)

set(QUICKBMS_ZIP "${REBLUE_TOOLS_ROOT}/quickbms/quickbms.zip")

if(NOT EXISTS ${QUICKBMS_EXECUTABLE})
    message(STATUS "Downloading QuickBMS...")
    file(DOWNLOAD 
        ${QUICKBMS_URL}
        ${QUICKBMS_ZIP}
    )
    file(ARCHIVE_EXTRACT INPUT ${QUICKBMS_ZIP}
         DESTINATION ${REBLUE_TOOLS_ROOT}/quickbms)
    message(STATUS "QuickBMS downloaded and extracted to ${REBLUE_TOOLS_ROOT}/quickbms")
    file(REMOVE QUICKBMS_ZIP)
endif()
