cmake_minimum_required(VERSION 4.0)

# set the project name and version
project(hangman VERSION 1.0)

add_library(project_compiler_flags INTERFACE)
target_compile_features(project_compiler_flags INTERFACE cxx_std_23)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(project_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;-Oz>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

add_executable(text_hangman text_hangman.cpp wordlist.cpp word.cpp text_gallows.cpp)
add_executable(testg testg.cpp text_gallows.cpp)

target_link_libraries(text_hangman PUBLIC project_compiler_flags)
target_link_libraries(testg        PUBLIC project_compiler_flags)

