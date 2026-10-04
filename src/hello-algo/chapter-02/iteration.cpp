#include <iostream>
#include <string>
#include <sstream>

int forLoop(int n);
int whileLoop(int n);
int whileLoopII(int n);
std::string nestedForLoop(int n);

int main() {
  int n = 10;

  std::cout << forLoop(n) << std::endl;
  std::cout << whileLoop(n) << std::endl;
  std::cout << whileLoopII(n) << std::endl;
  std::cout << nestedForLoop(n) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

/* For循环 */
int forLoop(int n) {
  int result = 0;

  // For循环：i = 1, 2, ……, n-1, n;
  for (int i = 1; i <= n; ++i) {
    result += i;
  }

  return result;
}

/* While循环 */
int whileLoop(int n) {
  int result = 0;

  int i = 1;
  // While循环;
  while (i <= n) {
    result += i;
    ++i;
  }

  return result;
}

/* For循环2 */
int whileLoopII(int n) {
  int result = 0;

  // while循环中两次操作；
  int i = 1;
  while ( i <= n) {
    result += i;
    ++i;
    i *= 2;
  }

  return result;
}

/* 嵌套For循环 */
std::string nestedForLoop(int n) {
  std::ostringstream result;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      result << "(" << i << "," << j << ")";
    }
    result << "\n";
  }

  return result.str();
}