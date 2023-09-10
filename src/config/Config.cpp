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

Result Config::setEndpoint(std::string Endpoint) {
  // change config in json file
  // operate

  if (1) {
    /* code */

    this->Endpoint = Endpoint;
    return Result::success;
  } else {
    return Result::failure;
  }
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