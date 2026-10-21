#include <iostream>

int recur(int n);
int tailRecur(int n, int result);

int main() {
  int n = 5;

  std::cout << "[普通递归]-> 1到" << n << "的和是：" << recur(n) << std::endl;
  std::cout << "[尾递归]-> 1到" << n << "的和是：" << tailRecur(n, 0)
            << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

int recur(int n) {
  // int result;
  if (n == 1) {
    return 1;
  }
  return n + recur(n - 1);
}

int tailRecur(int n, int result) {
  if (n == 0) {
    return result;
  }

  return tailRecur(n - 1, result + n);
}