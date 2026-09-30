#include <iostream>

long long factorial(int n, long long result);

int main(void) {
  long long result = 1;
  std::cout << "5的阶乘是：" << factorial(5, result) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}

long long factorial(int n, long long result) {
  if (0 == n) {
    return result;
  }

  return factorial(n - 1, result * n);
}