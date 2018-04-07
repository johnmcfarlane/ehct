project(cnl)

cmake_minimum_required(VERSION 3.7)

add_executable(enabled main.cpp s.cpp)
target_compile_features(enabled PUBLIC cxx_noexcept)
target_compile_options(enabled PRIVATE "-Wall" "-Wextra" "-Wpedantic" "-fexceptions" "-frtti")

add_executable(disabled main.cpp s.cpp)
target_compile_features(disabled PUBLIC cxx_noexcept)
target_compile_options(disabled PRIVATE "-Wall" "-Wextra" "-Wpedantic" "-fno-exceptions" "-fno-rtti")
