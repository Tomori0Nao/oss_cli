#include "config/Config.h"
#include "sonic/sonic.h"
#include "writebuffer.h"
#include <bits/types/FILE.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

using member_itr_type = typename sonic_json::Document::MemberIterator;

void print_member(member_itr_type m);
void set_new_value(member_itr_type m);

int main() {
  std::string config_file = "src/config/Config.json";

  std::ofstream config(config_file);


  std::string json = R"(
    {
      "Endpoint": 1,
      "AccessKeyId": 2,
      "AccessKeySecret":1234,
      "BucketName":433124
    }
  )";
  sonic_json::Document doc;
  doc.Parse(json);

  sonic_json::WriteBuffer wb;
  doc.Serialize(wb);

  std::cout << wb.ToString() << std::endl;
  config<< wb.ToString();
  config.close();

  if (doc.HasParseError()) {
    std::cout << "Parse failed!\n";
    return -1;
  }

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