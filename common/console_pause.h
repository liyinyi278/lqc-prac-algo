#pragma once
#include <iostream>

class ConsolePauseHelper {
 public:
  // 构造函数空实现，不影响程序启动
  ConsolePauseHelper() = default;

  // 析构函数：main 函数完全结束后自动执行
  ~ConsolePauseHelper(){
    std::cout << std::endl;
    std::cout << "按回车键退出...";
    std::cin.get();     
  }
};

static ConsolePauseHelper console_pase_helper;