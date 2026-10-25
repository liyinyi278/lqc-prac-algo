#include <iostream>
#include <vector>
int bubbleSort(std::vector<int>& nums);

int main() {
  std::vector<int> nums = {3, 6, 9, 2, 5, 4, 1, 0, 17, 13};

  std::cout << "原始数据：";
  for (int num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::cout << "算法复杂度分析：平方阶[10元素] -> 冒泡排序："
            << bubbleSort(nums) << std::endl;

  std::cout << "排序后数据：";
  for (int num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

int bubbleSort(std::vector<int>& nums) {
  int size = nums.size();
  int count = 0;

  for (int i = size - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] > nums[j + 1]) {
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
      ++count;
    }
  }

  return count;
}