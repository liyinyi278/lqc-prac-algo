#include <iostream>
#include <ostream>

void tailFibonacciOut(int n, int prevTwo, int prevOne);

int main(void) {
  long long result = 1;

  std::cout << "5的斐波那契数列是：";
  tailFibonacciOut(5, 0, 1);
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

void tailFibonacciOut(int n, int prevTwo, int prevOne) {
  if (n < 0) {
    return;
  }
  std::cout << prevTwo << " ";
  if (0 == n) {
    return;
  }

  tailFibonacciOut(n - 1, prevOne, prevTwo + prevOne);
}