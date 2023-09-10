#include <memory>
#include <string>
#include <utility>
#include <alibabacloud/oss/OssClient.h>
#include "Config.h"
#include "Result.h"

Config ::Config(std::string Endpoint, std::string AccessKeyId, std::string AccessKeySecret, std::string BucketName)
    : Endpoint(Endpoint), AccessKeyId(AccessKeyId), AccessKeySecret(AccessKeySecret), BucketName(BucketName)
{

    this->conf = new OSS::ClientConfiguration();
    this->client = new OSS::OssClient(Endpoint, AccessKeyId, AccessKeySecret, *(this->conf));
}

Config::~Config()
{
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

Result Config::setEndpoint(std::string Endpoint)
{
    // change config in json file
    // operate

    if (1)
    {
        /* code */

        this->Endpoint = Endpoint;
        return Result::success;
    }
    else
    {
        return Result::failure;
    }
}

Result Config::setAccessKeyId(std::string AccessKeyId)
{
    // change config in json file
    // operate
    if (1)
    {
        /* code */
        this->AccessKeyId = AccessKeyId;
        return Result::success;
    }
    else
    {
        return Result::failure;
    }
}
Result Config::setAccessKeySecret(std::string AccessKeySecret)
{
    // change config in json file
    // operate
    if (1)
    {
        /* code */
        this->AccessKeySecret = AccessKeySecret;
        return Result::success;
    }
    else
    {
        return Result::failure;
    }
}

Result Config::setBucketName(std::string BucketName)
{
    // change config in json file
    // operate
    if (1)
    {
        /* code */
        this->BucketName = BucketName;
        return Result::success;
    }
    else
    {
        return Result::failure;
    }
}