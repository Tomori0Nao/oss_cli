#ifndef __CONFIG_H
#define __CONFIG_H
#include <alibabacloud/oss/OssClient.h>
#include <memory>
#include "Result.h"
using namespace AlibabaCloud;
class Config
{
private:
    OSS::OssClient* client;
    OSS::ClientConfiguration* conf;

    std::string Endpoint ;
	/* 阿里云账号AccessKey拥有所有API的访问权限，风险很高。强烈建议您创建并使用RAM用户进行API访问或日常运维，请登录RAM控制台创建RAM用户。*/
	std::string AccessKeyId ;
	std::string AccessKeySecret ;
	std::string BucketName ;
   
    static std::unique_ptr<Config> instance;

    Config(std::string Endpoint, std::string AccessKeyId, std::string AccessKeySecret, std::string BucketName);

    Result setEndpoint(std::string Endpoint);

    Result setAccessKeyId(std::string AccessKeyId);

    Result setAccessKeySecret(std::string AccessKeySecret);

    Result setBucketName(std::string BucketName);



public:
    // Config(/* args */);
    ~Config();
    static std::unique_ptr<Config> getInstance(std::string Endpoint, std::string AccessKeyId, std::string AccessKeySecret, std::string BucketName);
};
#endif

