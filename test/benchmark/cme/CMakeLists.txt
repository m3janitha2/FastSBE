message("CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${PROJECT_SOURCE_DIR}/test/utility)

set (fast_sbe_dir "${PROJECT_SOURCE_DIR}/FastSBE")
set (py_cmd "${fast_sbe_dir}/FastSBE.py")
set (log_file "${CMAKE_CURRENT_LIST_DIR}/log.txt")
set (schema_file "${CME_TEMPLATE_FILE}")  # fetched on demand (see top-level CMakeLists)
set (out_folder "${CMAKE_CURRENT_LIST_DIR}/fastsbe")
set (override_namespace "fastsbe")

message("py_cmd is ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}" )

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/fastsbe/__header.h)
    message(FATAL_ERROR "File \"${CMAKE_CURRENT_LIST_DIR}/fastsbe/__header.h\" found, \
    this should never be created, remove!")
endif()

add_custom_target(
    cme_generate_fastsbe_schema ALL
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/fastsbe/__header.h
)

add_custom_command(
    OUTPUT
        ${CMAKE_CURRENT_LIST_DIR}/fastsbe/__header.h
        ${CMAKE_CURRENT_LIST_DIR}/fastsbe/MessageHeader.h
    COMMAND ${PYTHON_EXECUTABLE} ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}
    WORKING_DIRECTORY ${fast_sbe_dir}
)

add_executable(cme_benchmark_test benchmark_test.cpp
    ${CMAKE_CURRENT_LIST_DIR}/fastsbe/__header.h
)
target_link_libraries(cme_benchmark_test GTest::gtest GTest::gtest_main)
target_link_libraries(cme_benchmark_test benchmark::benchmark)

add_executable(cme_validation_test validation_test.cpp)
target_link_libraries(cme_validation_test GTest::gtest GTest::gtest_main)
target_link_libraries(cme_validation_test benchmark::benchmark)
add_test(NAME cme_validation COMMAND cme_validation_test)
