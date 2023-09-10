#include <memory>
#include <string>
#include <utility>
#include <alibabacloud/oss/OssClient.h>
#include "Config.h"
#include "Result.h"
#include <alibabacloud/oss/OssClient.h>
#include <alibabacloud/oss/client/ClientConfiguration.h>
#include <memory>
#include <string>
#include <type_traits>

Config ::Config(const std::string& Endpoint, const std::string& AccessKeyId,
                const std::string& AccessKeySecret, std::string BucketName)
    : conf(new OSS::ClientConfiguration()), Endpoint(Endpoint),
      AccessKeyId(AccessKeyId), AccessKeySecret(AccessKeySecret),
      BucketName(std::move(BucketName)) {
        // 在函数体中初始化，避免conf未初始化完成
  this->client = std::make_unique<OSS::OssClient>(
      Endpoint, AccessKeyId, AccessKeySecret, *(this->conf.get()));
}

Config::~Config() {}

Config *Config::getInstance() {
  if (instance == nullptr) {
    instance = new Config("a", "b", "c", "d");
    /* code */
  }
  return instance;
}

std::unique_ptr<Config> Config::getInstance(std::string Endpoint, std::string AccessKeyId, std::string AccessKeySecret, std::string BucketName)
{
    if (instance == nullptr)
    {
        instance = std::make_unique<Config>(new Config(std::move(Endpoint),std::move(AccessKeyId),std::move(AccessKeySecret),std::move(BucketName)));
        /* code */
        // std::make_unique()
    }
    return instance;
}

Result Config::setAccessKeyId(std::string AccessKeyId) {
  // change config in json file
  // operate
  if (1) {
    /* code */
    this->AccessKeyId = AccessKeyId;
    return Result::success;
  } else {
    return Result::failure;
  }
}
Result Config::setAccessKeySecret(std::string AccessKeySecret) {
  // change config in json file
  // operate
  if (1) {
    /* code */
    this->AccessKeySecret = AccessKeySecret;
    return Result::success;
  } else {
    return Result::failure;
  }
}

Result Config::setBucketName(std::string BucketName) {
  // change config in json file
  // operate
  if (1) {
    /* code */
    this->BucketName = BucketName;
    return Result::success;
  } else {
    return Result::failure;
  }
}