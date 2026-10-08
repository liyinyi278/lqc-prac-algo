#include <iostream>
#include <string>
void printTowerOfHanoi(int n, std::string from, std::string aux, std::string to,
                       int& count3);

int main() {
  std::cout << "汉诺塔-移动" << 5 << "个盘子的完整过程：" << "\n\n";
  int count3 = 0;

  printTowerOfHanoi(5, "A", "B", "C", count3);

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

void printTowerOfHanoi(int n, std::string from, std::string aux, std::string to,
                       int& count3) {
  if (n <= 0) {
    return;
  }

  if (1 == n) {
    std::cout << from << "-->" << to << std::endl;
    return;
  }

  printTowerOfHanoi(n - 1, from, to, aux, count3);
  if (n >= 3) {
    std::cout << "\n";
  }

  std::cout << from << "-->" << to << "\n";
  if (n >= 3) {
    std::cout << "\n";
  }

  printTowerOfHanoi(n - 1, aux, from, to, count3);
  if (3 == n) {
    ++count3;
    std::cout << "第" << count3 << "次完成3个盘子的移动：从" << from << "到"
              << to << "。\n";
  }
}