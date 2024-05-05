add_executable(AsyncLogTest AsyncLog.cpp)
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(AsyncLogTest PRIVATE spdlog::spdlog_header_only)

enable_testing()
find_package(GTest CONFIG REQUIRED)
target_link_libraries(AsyncLogTest PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(AllTestsInMain AsyncLogTest)