#include <iostream>

int quadratic(int n);

int main() {
  std::cout << "算法复杂度分析：平方阶 -> 10个元素：" << quadratic(10)
            << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

int quadratic(int n) {
  int count = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ++count;
    }
  }

  return count;
}