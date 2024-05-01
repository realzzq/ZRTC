project(ZRTC)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_TOOLCHAIN_FILE /home/cuishi/_ZZQ_LIB/scripts/buildsystems)


file(GLOB FILES
    ${CMAKE_SOURCE_DIR}/src/*/*
)
message("test: ${FILES}")
add_executable(ZRTC main.cpp ${FILES})
find_package(glog CONFIG REQUIRED)
    target_link_libraries(ZRTC PRIVATE glog::glog)
# find_package(nlohmann_json CONFIG REQUIRED)
#     target_link_libraries(ZRTC PRIVATE nlohmann_json::nlohmann_json)