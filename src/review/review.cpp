#include <iostream>
int addTailRecur(int n, int result);

int main(){
  std::cout << "使用尾递归计算：1 + …… + " << 5 << " = " << addTailRecur(5, 0) << std::endl;
  
  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}

// n：设置从1加到n的数；
// result：用于保存最终的和的变量，在使用时，应该初始化为0；
int addTailRecur(int n, int result) {
  if (0 == n) {
    return result;
  }

  return addTailRecur(n - 1, result + n);
}