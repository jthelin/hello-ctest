# hello-ctest

## Running build and test locally

In order to build and test this project locally, you need to follow 4 steps:

1. **Create the _Build environment_**

    Create a directory for all of the _generated_ files (e.g. make files, object files, executables etc.) will be located.
    This can be done by running the command like:
    ```shell
    cmake -E make_directory my_build_directory
    ```
    or something system specific like:
    ```shell
    mkdir -p my_build_directory
    ```

2. **Configure CMake**

    This step _generates_ all of the files needed for the build.
    Navigate to `my_build_directory` and run:
    ```shell
    cmake ../
    ```
    Expected output:
    ```
    -- The CXX compiler identification is GNU 13.2.0
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Check for working CXX compiler: /usr/bin/c++ - skipped
    -- Detecting CXX compile features
    -- Detecting CXX compile features - done
    -- Using CTEST_RESOURCE_SPEC_FILE = some_path/hello-ctest/test-resource-spec.json
    -- CMAKE_INSTALL_PREFIX = some_path/hello-ctest/my_build_directory/install/hello-ctest -- Use the cmake --install-prefix arg to override.
    -- Configuring done (0.2s)
    -- Generating done (0.0s)
    -- Build files have been written to: some_path/hello-ctest/my_build_directory
    ```

3. **Build the project**

    Navigate to `my_build_directory` and run:
    ```shell
    cmake --build .
    ```
    The output should look like:
    ```
    [ 50%] Building CXX object src/CMakeFiles/hello-ctest.dir/main.cpp.o
    [100%] Linking CXX executable hello-ctest
    [100%] Built target hello-ctest
    ```

4. **Execute the tests using `ctest`**

    Tests in this project are expresed using [`ctest`](https://cmake.org/cmake/help/latest/manual/ctest.1.html).
    To execute all of them navigate to `my_build_directory` and run:
    ```
    ctest
    ```
    The output should look like:
    ```
    Test project some_path/hello-ctest/my_build_directory
        Start 1: run_hello-ctest
    1/6 Test #1: run_hello-ctest ..................   Passed    0.00 sec
        Start 2: Hello_One
    2/6 Test #2: Hello_One ........................   Passed    0.00 sec
        Start 3: Hello_Two
    3/6 Test #3: Hello_Two ........................   Passed    0.00 sec
        Start 4: Hello_Three
    4/6 Test #4: Hello_Three ......................   Passed    0.00 sec
        Start 5: Hello_Four
    5/6 Test #5: Hello_Four .......................   Passed    0.00 sec
        Start 6: Hello_Five
    6/6 Test #6: Hello_Five .......................   Passed    0.00 sec

    100% tests passed, 0 tests failed out of 6

    Total Test time (real) =   0.02 sec
    ```

These steps are reflected in [`build_and_test.yml`](.github/workflows/build_and_test.yml) workflow.
