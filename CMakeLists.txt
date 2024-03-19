cmake_minimum_required(VERSION 3.10)
project(FiniteFields)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB 
    src/ff.c
)

add_library(finite_fields STATIC ${SOURCE_LIB})	
target_include_directories(finite_fields PUBLIC src)
target_link_libraries(finite_fields m)

# Add compiler flags
target_compile_options(finite_fields PRIVATE -Wall -g)

# Executable tests
add_executable(tests tests/ff_test.c)
target_link_libraries(tests finite_fields)

enable_testing()

add_test(NAME Tests COMMAND tests)

# Group files to format
file(GLOB_RECURSE ALL_SOURCE_FILES *.c *.h)
foreach (SOURCE_FILE ${ALL_SOURCE_FILES})
    string(FIND SOURCE_FILE PROJECT_TRDPARTY_DIR PROJECT_TRDPARTY_DIR_FOUND)
    if (NOT ${PROJECT_TRDPARTY_DIR_FOUND} EQUAL -1)
        list(REMOVE_ITEM ALL_SOURCE_FILES ${SOURCE_FILE})
    endif ()
endforeach ()

# Formatter
add_custom_target (format
     COMMAND clang-format -style=Google -i ${ALL_SOURCE_FILES})

# Memcheck
add_custom_target(memcheck 
    COMMAND valgrind --leak-check=full -s ./tests)
