add_executable(${PROJECT_NAME}
    main.cpp
)

add_test(NAME run_${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
