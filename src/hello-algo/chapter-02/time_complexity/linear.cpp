#include <iostream>
int linear(int n);

int main() {
  std::cout << "线性阶[1000]：\t" << linear(1000) << std::endl;
  std::cout << "线性阶[10000]：\t" << linear(10000) << std::endl;
  std::cout << "线性阶[100000]：" << linear(100000) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

int linear(int n) {
  int count = 0;

  for (int i = 0; i < n; ++i) {
    ++count;
  }

  return count;
}