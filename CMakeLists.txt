cmake_minimum_required(VERSION 3.22)
set(CMAKE_TOOLCHAIN_FILE /home/zdq/APP/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(ZRTC)




file(GLOB FILES
    ${CMAKE_SOURCE_DIR}/src/*/*
)
message("test: ${FILES}")
add_executable(ZRTC main.cpp ${FILES})
find_package(glog CONFIG REQUIRED)
  target_link_libraries(ZRTC PRIVATE glog::glog)

  
enable_testing()
  
  find_package(GTest CONFIG REQUIRED)
  target_link_libraries(ZRTC PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
  
  add_test(AllTestsInMain ZRTC)
# find_package(nlohmann_json CONFIG REQUIRED)
#     target_link_libraries(ZRTC PRIVATE nlohmann_json::nlohmann_json)