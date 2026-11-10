#include <iostream>
int expRecur(int n);

int main() {
  std::cout << "算法复杂度分析-注：包含分裂后消失的父细胞 ：" << "\n\n";
  // std::cout << "指数阶[10元素]-每轮分裂后的细胞个数 ：";
  int count = expRecur(10);
  std::cout << "指数阶[10元素]-最终分裂的所有细胞个数 ：" << count << std::endl;
  return 0;
}

int expRecur(int n){
  if (n <= 0) {
    return -1;
  }

  if (1 == n) {
    return 1;
  }

  return expRecur(n - 1) + expRecur(n - 1) + 1;
}