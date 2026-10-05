#include <iostream>
int multiply(int A, int B);

int main() {
  std::cout << 1 << " * " << 10 << " = " << multiply(1, 10) << std::endl;
  std::cout << 3 << " * " << 4 << " = " << multiply(3, 4) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}

int multiply(int A, int B) {
  if (A < 0 || B < 0) {
    return -1;
  }

  if (A < B) {
    int temp = A;
    A = B;
    B = temp;
  }

  if (0 == B) {
    return 0;
  }

  return (multiply(A, B >> 1) << 1) + ((B & 1) ? A : 0);
}