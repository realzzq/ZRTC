cmake_minimum_required(VERSION 3.22)
set(CMAKE_TOOLCHAIN_FILE /home/zdq/APP/vcpkg/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_CXX_STANDARD 17)
project(ZRTC)

file(GLOB FILES
    ${CMAKE_SOURCE_DIR}/src/*/*
)
message("test: ${FILES}")
add_executable(ZRTC main.cpp ${FILES})

add_subdirectory(test)

# find_package(nlohmann_json CONFIG REQUIRED)
#     target_link_libraries(ZRTC PRIVATE nlohmann_json::nlohmann_json)