#include <iostream>
#include <ostream>

int tailFibonacci(int n, int current, int next);

int main(void) {
  std::cout << "尾递归 -> 斐波那契数列的第5位是：" << tailFibonacci(5, 0, 1)
            << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

/* 计算从 F(0) 到 F(n)的值，current初始化为F(0)，next初始化为(F1)；*/
/* 初始调用示例： tailFibonacciOut(5, 0, 1) */
int tailFibonacci(int n, int current, int next) {
  // (0 > n)，用于非法输入的检验：
  if (0 > n) {
    return -1;
  }
  // (0 == n)用于边界基准条件的检查，比如：初始输入 `n=0`。
  if (0 == n) {
    return current;
  }
  if (1 == n) {
    return next;
  }

  return tailFibonacci(n - 1, next, current + next );
}