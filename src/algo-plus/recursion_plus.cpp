#include <iostream>

long long tailFactorial(int n, long long result);

int main(void) {
  long long result = 1;
  std::cout << "5的阶乘是：" << tailFactorial(5, result) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

long long tailFactorial(int n, long long result) {
  if (0 == n) {
    return result;
  }

  return tailFactorial(n - 1, result * n);
}

int tailFabonacci(int n, int beforeTwo, int beforeOne) {
  if (0 == n) {
    return beforeTwo;
  }
  if (1 == n) {
    return beforeOne;
  }

  return tailFabonacci(n - 1, beforeOne, beforeOne + beforeTwo) ;
}