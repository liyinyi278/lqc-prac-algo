#include <iostream>
long long factorial(int n);

int main() {
  std::cout << "使用递归计算阶乘: F(" << 5 << ") = " << factorial(5)
            << std::endl;
            
  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

long long factorial(int n) {
  if (1 == n) {
    return 1;
  }

  return n * factorial(n - 1);
}