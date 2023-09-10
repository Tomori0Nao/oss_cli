#include "Result.h"
#include "config/Config.h"
#include "sonic/sonic.h"
#include "writebuffer.h"
#include <bits/types/FILE.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

#define CONFIG_FILE_PATH "src/config/Config.json"

using member_itr_type = typename sonic_json::Document::MemberIterator;

void print_member(member_itr_type m);
void set_new_value(member_itr_type m);
Result loadConfig();



int main() {

  loadConfig();
  // std::string config_file = "src/config/Config.json";

  // std::ofstream config(CONFIG_FILE_PATH);


  // std::string json = R"(
  //   {
  //     "Endpoint": "oss-cn-chengdu.aliyuncs.com",
  //     "AccessKeyId":"LTAI5tK5RfE9vo7CwWGh78VQ" ,
  //     "AccessKeySecret":"N59VI37GnYmuZ0tHDcBgRESySUjOS9",
  //     "BucketName":"news-photo-test"
  //   }
  // )";
  // sonic_json::Document doc;
  // doc.Parse(json);

  // sonic_json::WriteBuffer wb;
  // doc.Serialize(wb);

  // std::cout << wb.ToString() << std::endl;
  // config<< wb.ToString();
  // config.close();

  // if (doc.HasParseError()) {
  //   std::cout << "Parse failed!\n";
  //   return -1;
  // }

  return 0;
}

using member_itr_type = typename sonic_json::Document::MemberIterator;

void print_member(member_itr_type m) {
  const sonic_json::Node &key = m->name;
  sonic_json::Node &value = m->value;
  if (key.IsString()) {
    std::cout << "Key is: " << key.GetString() << std::endl;
  } else {
    std::cout << "Incoreect key type!\n";
    return;
  }
  if (value.IsInt64()) {
    std::cout << "Value is " << value.GetInt64() << std::endl;
  }

  return;
}

void set_new_value(member_itr_type m) {
  sonic_json::Node &value = m->value;
  value.SetInt64(2);
  return;
}

Result loadConfig() {
  std::ifstream config_file_stream(CONFIG_FILE_PATH);

  std::string json;

  std::getline(config_file_stream,json);

  sonic_json::Document doc;

  config_file_stream.close();
  
  std::cout << json<< std::endl;

  return  Result::success;
  doc.Parse(json);

  

}