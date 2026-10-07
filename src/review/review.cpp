#include <iostream>
long long tailFactorial(int n, long long result);

int main() {
  std::cout << "使用尾递归计算阶乘： F(" << 5 << ") = " << tailFactorial(5, 1)
            << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

// result：应该初始化为1；
long long tailFactorial(int n, long long result) {
  if (1 == n) {
    return result;
  }

  return tailFactorial(n - 1, result * n);
}