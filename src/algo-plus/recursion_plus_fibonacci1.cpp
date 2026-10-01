#include <iostream>
#include <ostream>

int tailFibonacci(int n, int prevTwo, int prevOne);

int main(void) {
  long long result = 1;
  std::cout << "尾递归 -> 斐波那契数列的第5位是：" << tailFibonacci(5, 0, 1)
            << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

int tailFibonacci(int n, int prevTwo, int prevOne) {
  if (0 == n) {
    return prevTwo;
  }
  if (1 == n) {
    return prevOne;
  }

  return tailFibonacci(n - 1, prevOne, prevOne + prevTwo);
}