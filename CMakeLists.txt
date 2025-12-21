cmake_minimum_required(VERSION 3.28)

# set the project name and version
project(hangman LANGUAGES CXX VERSION 1.08)

set(CMAKE_CXX_STANDARD 23)

# Generate compile_commands.json for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

# Dependencies
include(FetchContent)

# Fetch raylib
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW 1
)
FetchContent_MakeAvailable(raylib)

add_library (hangman
    config.cpp 
    wordlist.cpp 
    word.cpp 
)

add_executable(testg testg.cpp text_gallows.cpp)
add_executable(testconfig testconfig.cpp)
add_executable(text_hangman
    text_hangman.cpp 
    text_game.cpp 
    text_gallows.cpp
)
add_executable(raylib_hangman 
    raylib_hangman.cpp 
    raylib_game.cpp 
    letter_grid.cpp 
    images.cpp
)

target_link_libraries(raylib_hangman hangman raylib)
target_link_libraries(text_hangman hangman)
target_link_libraries(testconfig hangman)

# Platform-specific settings
if(APPLE)
    target_link_libraries(raylib_hangman "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()

