#include <iostream>
int constant(int n);

int main(){
  std::cout << "常数阶[005]的结果是：" << constant(5) << std::endl;
  std::cout << "常数阶[015]的结果是：" << constant(15) << std::endl;
  std::cout << "常数阶[115]的结果是：" << constant(115) << std::endl;
  
  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}

int constant(int n){
  int count = 0;
  int size = 100000;

  for (int i = 0; i < size; ++i) {
    ++count;
  }

  return count;
}