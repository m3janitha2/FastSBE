cmake_minimum_required (VERSION 3.16)

project(FastSBE VERSION 1.0)

set(CMAKE_CPP_COMPILER g++)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    message("setting CMAKE_CXX_FLAGS")
    set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_CXX_FLAGS "-O3")
endif()

include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

set(BENCHMARK_ENABLE_TESTING OFF)

FetchContent_Declare(
	googlebenchmark
	GIT_REPOSITORY https://github.com/google/benchmark
	GIT_TAG v1.6.0
)

FetchContent_MakeAvailable(googlebenchmark)

include(FindPythonInterp)

enable_testing()

# ---------------------------------------------------------------------------
# CME SBE templates are CME's third-party IP and are not vendored in this repo;
# they are fetched on demand at configure time. FTP is the default source
# because CME's HTTPS host (www.cmegroup.com) sits behind a CDN that returns
# 403 to non-browser clients, whereas ftp.cmegroup.com serves the same file
# unprotected.
#
#   change the source:    -DCME_TEMPLATE_URL=<url>
#   use a local copy      (skips the download; e.g. pinned / air-gapped CI):
#                         -DCME_TEMPLATE_FILE=/path/to/templates_FixBinary.xml
# ---------------------------------------------------------------------------
set(CME_TEMPLATE_URL
    "ftp://ftp.cmegroup.com/SBEFix/Production/Templates/templates_FixBinary.xml"
    CACHE STRING "Source URL for the CME MDP 3.0 SBE template schema")
set(CME_TEMPLATE_FILE
    "${CMAKE_BINARY_DIR}/cme_templates/templates_FixBinary.xml"
    CACHE FILEPATH "CME SBE template; downloaded from CME_TEMPLATE_URL if absent")

if(NOT EXISTS "${CME_TEMPLATE_FILE}")
    message(STATUS "Fetching CME SBE template: ${CME_TEMPLATE_URL}")
    file(DOWNLOAD "${CME_TEMPLATE_URL}" "${CME_TEMPLATE_FILE}"
         STATUS _cme_dl TLS_VERIFY ON SHOW_PROGRESS)
    list(GET _cme_dl 0 _cme_dl_code)
    if(NOT _cme_dl_code EQUAL 0)
        list(GET _cme_dl 1 _cme_dl_msg)
        file(REMOVE "${CME_TEMPLATE_FILE}")  # never leave a partial file behind
        message(FATAL_ERROR
            "Could not download the CME SBE template (${_cme_dl_code}: ${_cme_dl_msg}).\n"
            "  URL: ${CME_TEMPLATE_URL}\n"
            "If your network blocks FTP, download it manually and re-configure with\n"
            "  -DCME_TEMPLATE_FILE=/path/to/templates_FixBinary.xml")
    endif()
endif()

add_subdirectory(test)
#add_subdirectory(example)


