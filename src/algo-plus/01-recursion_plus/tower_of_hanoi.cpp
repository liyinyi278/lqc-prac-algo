#include <iostream>
#include <ostream>
#include <string>

void printTowerOfHanoi(int n, std::string from, std::string aux,
                       std::string to);
int main(void) {
  std::cout << "3个盘子的汉诺塔移动方法：" << std::endl;
  printTowerOfHanoi(3, "A", "B", "C");

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}

void printTowerOfHanoi(int n, std::string from, std::string aux,
                       std::string to) {
  if (1 == n) {
    std::cout << from << "-->" << to << std::endl;
    return;
  }
  // if (2 == n) {
  //   std::cout << from << "-->" << aux << std::endl;
  //   std::cout << from << "-->" << to << std::endl;
  //   std::cout << aux << "-->" << to << std::endl;
  // }

  printTowerOfHanoi(n - 1, from, to, aux);
  std::cout << from << "-->" << to << std::endl;
  printTowerOfHanoi(n - 1, aux, from, to);

  return;
}