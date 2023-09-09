#include <iostream>
#include <alibabacloud/oss/OssClient.h>
#include <string>
#include <fstream>
#include "Result.h"
#include "Utils.h"
using namespace AlibabaCloud;

class OssUpload
{
private:
    /* data */
    Result result;
    Result fileUpload(FileQue &fileQue);

public:
    OssUpload(/* args */);
    ~OssUpload();
};

OssUpload::OssUpload(/* args */)
{
}

OssUpload::~OssUpload()
{
}

Result OssUpload::fileUpload(FileQue &fileQue)
{
    return Result::success;
}
