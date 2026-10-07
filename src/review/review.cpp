#include <iostream>
void printTailFibonacci(int n, long long current, long long next, int& count);

int main() {
  int count = 0;
  std::cout << "斐波那契数列： F（" << 25 << "） （模式：0， 1）：\n";
  printTailFibonacci(25, 0, 1, count);

  count = 0;
  std::cout << "斐波那契数列： F（" << 25 << "） （模式：1， 1）：\n";
  printTailFibonacci(25, 1, 1, count);

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}
// current和next，初始化为要打印的斐波那契数列的第1个和第2个起始数字；
// 初始化时，currnet和next分别可以是：0， 1或 1， 1这两种模式；
void printTailFibonacci(int n, long long current, long long next, int& count) {
  if (0 == n) {
    std::cout << "\n" << std::endl;
    return;
  }

  std::cout << current << "\t";
  ++count;
  if (0 == (count % 10)) {
    std::cout << "\n";
  }

  printTailFibonacci(n - 1, next, current + next, count);
}