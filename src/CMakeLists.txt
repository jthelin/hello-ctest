add_executable(${PROJECT_NAME}
    main.cpp
)

add_test(NAME run_${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)

add_test(NAME Hello_One
    COMMAND ${PROJECT_NAME} One
)
add_test(NAME Hello_Two
    COMMAND ${PROJECT_NAME} Two
)
add_test(NAME Hello_Three
    COMMAND ${PROJECT_NAME} Three
)
add_test(NAME Hello_Four
    COMMAND ${PROJECT_NAME} Four
)
add_test(NAME Hello_Five
    COMMAND ${PROJECT_NAME} Five
)

cmake_path(SET CTEST_RESOURCE_SPEC_FILE NORMALIZE ${CMAKE_SOURCE_DIR}/test-resource-spec.json)
message(STATUS "Using CTEST_RESOURCE_SPEC_FILE = ${CTEST_RESOURCE_SPEC_FILE}")

set_tests_properties(
    Hello_One
    PROPERTIES RESOURCE_GROUPS "devices:1"
)
set_tests_properties(
    Hello_Two
    PROPERTIES RESOURCE_GROUPS "devices:2"
)
set_tests_properties(
    Hello_Three
    PROPERTIES RESOURCE_GROUPS "devices:3"
)
set_tests_properties(
    Hello_Four
    PROPERTIES RESOURCE_GROUPS "devices:4"
)
