cmake_minimum_required(VERSION 3.20)
project(lunadb LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(lunadb
    src/storage/file/block.cpp
)

target_include_directories(lunadb
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Test Executable
add_executable(lunadb_tests
    tests/storage/file/test_block.cpp
)

target_link_libraries(lunadb_tests
    PRIVATE
    lunadb
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(lunadb_tests)