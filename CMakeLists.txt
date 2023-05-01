# CMakeLists files in this project can
# refer to the root source directory of the project as ${DevRTOS_SOURCE_DIR} and
# to the root binary directory of the project as ${DevRTOS_BINARY_DIR}.
cmake_minimum_required (VERSION 3.22)
project (DevRTOS)

# Recurse into the "Source" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (source)
