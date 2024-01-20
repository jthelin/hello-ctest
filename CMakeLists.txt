cmake_minimum_required(VERSION 3.20)

project(hello-ctest
    VERSION 0.0.1
    DESCRIPTION "An example of using ctest for a C++ app / library."
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(src)

# cpack instructions

include(CPack)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)
