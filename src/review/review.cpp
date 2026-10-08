#include <iostream>
long long ackerman(int m, int n);

int main() {
  std::cout << "阿克曼函数（3， 2）的结果是：" << ackerman(3, 2) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

long long ackerman(int m, int n) {
  if (m < 0 || n < 0) {
    return -1;
  }

  if (0 == m) {
    return n + 1;
  } else if (0 == n) {
    return ackerman(m - 1, 1);
  } else {
    return ackerman(m - 1, ackerman(m, n - 1));
  }
}