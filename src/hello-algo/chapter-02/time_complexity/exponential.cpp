#include <iostream>
int exponential(int n);

int main() {
  std::cout << "算法复杂度分析：指数阶[10元素] ：" << exponential(10)
            << std::endl;
  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

/* 模拟细胞分裂的指数级算法复杂度 */
int exponential(int n) {  // n：分裂轮数
  int count = 0;          // 分裂总次数
  int base = 1;           // 细胞分裂前的基础个数

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < base; ++j) {
      ++count;
    }
    base *= 2;
  }

  return count;
}