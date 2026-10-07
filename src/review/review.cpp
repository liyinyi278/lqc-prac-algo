#include <iostream>
long long tailFibonacci(int n, long long current, long long next);

int main() {
  std::cout << "利用尾递归计算： F（" << 5 << "）的值（0， 1模式）"
            << tailFibonacci(5, 0, 1) << std::endl;
  std::cout << "利用尾递归计算： F（" << 5 << "）的值（1， 1模式）"
            << tailFibonacci(5, 1, 1) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

// current和next两个参数，分别代表记算斐波那契数列的起始位置的第1位和第2位；
// 初始化时，可以设置为：0， 1 或 1， 1两种模式；
long long tailFibonacci(int n, long long current, long long next) {
  if (0 == n) {
    return current;
  }

  return tailFibonacci(n - 1, next, current + next);
}