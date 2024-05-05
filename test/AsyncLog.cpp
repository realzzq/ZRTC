#include <gtest/gtest.h>

#include <chrono>
#include <filesystem>
#include <random>

#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/spdlog.h"

TEST(HelloWorldTest, BasicTest) {
  // Test code goes here
  // You can use ASSERT_* or EXPECT_* macros to perform assertions
  ASSERT_EQ(2 + 2, 4);
}

// 创建要写入的文件夹并指定要写入的日志文件名称
TEST(WriteFile, BasicTest) {
  spdlog::info("Test: {}", 1);

  try {
    // 在logs/basic.txt中写下Hello world
    auto my_logger =
        spdlog::basic_logger_mt("sbasic_logger", "./logs/basic.txt");
    my_logger->info("Hello {}", "world");
  } catch (const spdlog::spdlog_ex& ex) {
    std::cout << "Log initialization failed: " << ex.what() << std::endl;
  }
}

// 异步写入文件
TEST(AsyncWrite, BasicTest) {
  auto start = std::chrono::system_clock::now();
  spdlog::init_thread_pool(10000, 10);
  auto file_logger = spdlog::rotating_logger_mt<spdlog::async_factory>(
      "Async", "./logs/AsyncLogs", 1024 * 1024 * 5, 100);
  int i = 0;
  file_logger->set_level(spdlog::level::debug);
  while (i < 1000000) {
    file_logger->debug("Async message #{}", i);
    i++;
  }
  auto end = std::chrono::system_clock::now();
  auto diff = end - start;
  file_logger->info("Async Duration: {}", diff.count());
  spdlog::drop_all();
}

// 同步写入文件
TEST(SyncWrite, BasicTest) {
  auto start = std::chrono::system_clock::now();

  auto file_logger =
      spdlog::rotating_logger_mt("Sync", "SyncLogs", 1024 * 1024 * 5, 100);
  file_logger->set_level(spdlog::level::debug);
  int i = 0;
  while (i < 1000000) {
    file_logger->debug("Async message #{}", i);
    i++;
  }

  auto end = std::chrono::system_clock::now();
  auto diff = end - start;
  file_logger->info("Sync Duration: {}", diff.count());
  // spdlog::info("Sync Duration: {}", diff.count());
  spdlog::drop_all();
}