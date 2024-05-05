add_executable(AsyncLogTest AsyncLog.cpp)
find_package(glog CONFIG REQUIRED)
target_link_libraries(AsyncLogTest PRIVATE glog::glog)

enable_testing()
find_package(GTest CONFIG REQUIRED)
target_link_libraries(AsyncLogTest PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(AllTestsInMain AsyncLogTest)