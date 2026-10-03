#include <iostream>
#include <ostream>

void tailFibonacciOut(int n, int current, int next);

int main(void) {
  std::cout << "F(0)~F(5)的斐波那契数列是：";
  tailFibonacciOut(5, 0, 1);
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

/* 打印从 F(0) 到 F(n)的整个数列，current初始化为F(0)，next初始化为(F1)；*/
/* 初始调用示例： tailFibonacciOut(5, 0, 1) */
void tailFibonacciOut(int n, int current, int next) {
  if (n < 0) {
    return;
  }
  std::cout << current << " ";
  if (0 == n) {
    return;
  }

  tailFibonacciOut(n - 1, next, current + next);
}