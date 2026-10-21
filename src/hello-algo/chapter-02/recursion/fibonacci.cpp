#include <iostream>
long long fib(int n);

int main() {
  std::cout << "斐波那契数列第" << 7 << "个数字是：" << fib(7) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}
long long fib(int n) {
  if (n <= 0) {
    return -1;
  }
  
  if (1 == n) {
    return 0;
  }
  if (2 == n) {
    return 1;
  }

  return fib(n - 1) + fib(n - 2);
}