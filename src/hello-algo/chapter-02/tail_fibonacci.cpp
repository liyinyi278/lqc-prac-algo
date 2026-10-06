#include <iostream>
long long tailFib(int n, int current, int next);

int main(){
  std::cout << "斐波那契数列第" << 7 << "个数字是：" << tailFib(7, 0, 1) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}

    long long tailFib(int n, int current, int next) {
  if (n <= 0) {
    return -1;
  }

  if (1 == n) {
    return current;
  }

  return tailFib(n - 1, next, current + next);
}