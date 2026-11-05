#include <iostream>
int exponential(int n);

int main() {
  std::cout << "算法复杂度分析-注：包含分裂后消失的父细胞 ：" << "\n\n";
  std::cout << "指数阶[10元素]-每轮分裂后的细胞个数 ：";
  int count = exponential(10);
  std::cout << "指数阶[10元素]-最终分裂的所有细胞个数 ：" << count << std::endl;
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
    std::cout << count << " ";
    base *= 2;
  }
  std::cout << std::endl;

  return count;
}