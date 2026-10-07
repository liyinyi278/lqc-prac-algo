#include <iostream>
int addRecur(int n) ;

int main(){
  std::cout << "使用递归计算：1 + …… + " << 5 << " = " << addRecur(5) << std::endl;
  
  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}

int addRecur(int n) {
  if (0 == n) {
    return 0;
  }

  return n + addRecur(n - 1);
}