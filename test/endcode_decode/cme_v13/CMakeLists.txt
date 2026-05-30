message("CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")

# CME MDP 3.0 v13 codec generation, for iterative testing and fixes.
#
# Generation is currently INCOMPLETE: FastSBE emits the enum/composite types
# but not the messages (it stops on the first unsupported construct - e.g.
# <set> fields such as MatchEventIndicator). This target exists to drive
# those generator fixes; it is deliberately NOT part of the default build, so
# the incomplete CME output cannot break the main test suite.
#
# Run on demand:
#     cmake --build build --target cme_v13_generate

include(FindPythonInterp)

set(fast_sbe_dir "${PROJECT_SOURCE_DIR}/FastSBE")
set(py_cmd "${fast_sbe_dir}/FastSBE.py")
set(log_file "${CMAKE_CURRENT_LIST_DIR}/log.txt")
set(schema_file "${CMAKE_CURRENT_LIST_DIR}/cme-mdp3-v13.xml")
set(out_folder "${CMAKE_CURRENT_LIST_DIR}/generated")
set(override_namespace "cme")

add_custom_target(cme_v13_generate
    COMMAND ${PYTHON_EXECUTABLE} ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}
    WORKING_DIRECTORY ${fast_sbe_dir}
    COMMENT "Generating CME MDP3 v13 codec from cme-mdp3-v13.xml -> generated/"
)
