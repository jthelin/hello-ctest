cmake_minimum_required(VERSION 3.21)

project(hello-ctest
    VERSION 0.0.1
    DESCRIPTION "An example of using ctest for a C++ app / library."
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(src)

# install package instructions

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  # Set a default "local" install staging location to avoid accidentally trying to install into /usr/local/bin etc.
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install/${PROJECT_NAME}" CACHE PATH "CMAKE_INSTALL_PREFIX" FORCE)
endif()
message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX} -- Use the cmake --install-prefix arg to override.")

include(CPack)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
    LIBRARY DESTINATION lib
)
# Files for the root directory of the install tree - LICENSE, README, etc.
install(FILES
    LICENSE
    README.md
    DESTINATION .
)
