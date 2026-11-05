#pragma once
#include <windows.h>

class ConsoleUTF8Initializer{
  public:
    ConsoleUTF8Initializer(){
      SetConsoleOutputCP(65001);  // 输出代码页设为 UTF-8
      SetConsoleCP(65001);        // 输入代码页设为 UTF-8
    }
};

// 全局静态对象，程序启动时自动构造，执行初始化
static ConsoleUTF8Initializer console_utf8_init;