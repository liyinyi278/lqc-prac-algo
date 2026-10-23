#include <iostream>
#include <vector>
int arrayTraversal(std::vector<int> nums);

int main() {
  std::vector<int> nums;

  for (int i = 0; i < 10; ++i) {
    nums.push_back(i);
  }

  std::cout << "算法复杂度分析：线性阶[数组迭代] -> 10个元素："
            << arrayTraversal(nums) << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

int arrayTraversal(std::vector<int> nums) {
  int count = 0;

  for (int num : nums) {
    ++count;
  }

  return count;
}