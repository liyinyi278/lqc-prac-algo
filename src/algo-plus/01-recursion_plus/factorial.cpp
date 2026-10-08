#include <iostream>
#include <ostream>

long long tailFactorial(int n, long long result);

int main() {
  long long result = 1;
  std::cout << "尾递归 -> 5的阶乘是：" << tailFactorial(5, result) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

long long tailFactorial(int n, long long result) {
  if (n < 0) {
    return -1;
  }
  if (0 == n) {
    return result;
  }

  return tailFactorial(n - 1, result * n);
}