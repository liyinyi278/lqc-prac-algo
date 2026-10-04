#include <iostream>
#include <string>

void printTowerOfHanoi(int n, std::string from, std::string aux,
                       std::string to, int &count3);
int main() {
  int count3 = 0;
  
  std::cout << "5个盘子的汉诺塔移动方法：\n\n";
  printTowerOfHanoi(5, "A", "B", "C", count3);

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}

void printTowerOfHanoi(int n, std::string from, std::string aux,
                       std::string to, int &count3) {
  if (1 == n) {
    std::cout << from << "-->" << to << std::endl;
    return;
  }

  printTowerOfHanoi(n - 1, from, to, aux, count3);
  if (n >= 3) {
    std::cout << std::endl;
  }
  
  std::cout << from << "-->" << to << std::endl;
  if (n >= 3) {
    std::cout << std::endl;    
  }
  
  printTowerOfHanoi(n - 1, aux, from, to, count3);
  if (3 == n) {
    ++count3;
    std::cout << "第" << count3 << "次完成3个盘子移动：从" << from << "到" << to
              << "。" << std::endl;
  }

  return;
}