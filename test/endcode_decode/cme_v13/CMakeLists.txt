message("CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")

# CME MDP 3.0 v13: regenerate the codec from cme-mdp3-v13.xml on every build
# (generated/ is not committed) and round-trip MDIncrementalRefreshBook46 in
# encode_decode.cpp.

include(FindPythonInterp)

set(fast_sbe_dir "${PROJECT_SOURCE_DIR}/FastSBE")
set(py_cmd "${fast_sbe_dir}/FastSBE.py")
set(log_file "${CMAKE_CURRENT_LIST_DIR}/log.txt")
set(schema_file "${CMAKE_CURRENT_LIST_DIR}/cme-mdp3-v13.xml")
set(out_folder "${CMAKE_CURRENT_LIST_DIR}/generated")
set(override_namespace "cme")

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h)
    message(FATAL_ERROR "File \"${CMAKE_CURRENT_LIST_DIR}/generated/__header.h\" found, \
    this should never be created, remove!")
endif()

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${PROJECT_SOURCE_DIR}/test/utility)
include_directories(${CMAKE_CURRENT_LIST_DIR}/generated)

add_custom_target(
    cme_v13_target ALL
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
)

add_custom_command(
    OUTPUT
        ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
        ${CMAKE_CURRENT_LIST_DIR}/generated/MDIncrementalRefreshBook46.h
    COMMAND ${PYTHON_EXECUTABLE} ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}
    WORKING_DIRECTORY ${fast_sbe_dir}
)

add_executable(cme_v13_encode_decode encode_decode.cpp
    ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
)
target_link_libraries(cme_v13_encode_decode GTest::gtest GTest::gtest_main)
add_test(NAME cme_v13_encode_decode COMMAND cme_v13_encode_decode)
