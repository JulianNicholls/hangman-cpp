cmake_minimum_required(VERSION 4.0)

# set the project name and version
project(hangman LANGUAGES CXX VERSION 2.0alpha)

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

add_executable(text_hangman text_hangman.cpp wordlist.cpp word.cpp text_gallows.cpp)
add_executable(testg testg.cpp text_gallows.cpp)
add_executable(raylib_hangman 
    raylib_hangman.cpp 
    raylib_game.cpp 
    wordlist.cpp 
    word.cpp 
    graphic_gallows.cpp 
    letter_grid.cpp 
    images.cpp
)

target_link_libraries(raylib_hangman raylib)

# Platform-specific settings
if(APPLE)
    target_link_libraries(raylib_hangman "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()

