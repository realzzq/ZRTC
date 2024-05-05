#include <glog/logging.h>
#include <gtest/gtest.h>

#include <chrono>
#include <filesystem>
#include <random>

TEST(HelloWorldTest, BasicTest) {
  // Test code goes here
  // You can use ASSERT_* or EXPECT_* macros to perform assertions
  ASSERT_EQ(2 + 2, 4);
}

// 创建要写入的文件夹并指定要写入的日志文件名称
TEST(WriteFile, BasicTest) {
  std::string log_path = "../../log";
  FLAGS_log_dir = log_path;
  printf("test\n");
  google::SetLogSymlink(google::GLOG_INFO, "Info");
  google::SetLogSymlink(google::GLOG_WARNING, "Warning");
  google::SetLogSymlink(google::GLOG_ERROR, "Error");
  google::InitGoogleLogging("WriteLog");
  if (!std::filesystem::exists(log_path)) {
    if (std::filesystem::create_directories(log_path)) {
      LOG(INFO) << "创建成功";
    }
  } else {
    LOG(WARNING) << "文件夹" + log_path + "已经存在，不用创建";
  }
  LOG(INFO) << "file";
  // Most flags work immediately after updating values.
  FLAGS_logtostderr = 1;
  LOG(INFO) << "stderr";
  FLAGS_logtostderr = 0;
  // This won’t change the log destination. If you want to set this
  // value, you should do this before google::InitGoogleLogging .
  //   FLAGS_log_dir = "/some/log/directory";
  LOG(INFO) << "the same file";

  for (int i = 0; i < 100; i++) {
    if (i % 2 == 0) {
      LOG(INFO) << "Test Write INFO" << i;
    } else {
      LOG(ERROR) << "Test Write ERROR" << i;
    }
  }
}