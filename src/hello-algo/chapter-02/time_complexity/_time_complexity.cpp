#include <iostream>
#include <vector>

int constant(int n);
int linear(int n);
int arrayTraversal(std::vector<int>& nums);
int quadratic(int n);
int bubbleSort(std::vector<int>& nums);
int exponential(int n);
int expRecur(int n, int& count);
int logarithmic(int n);
int logRecur(int n);
int linearRecur(int n);
int factorialRecur(int n);

int main() {
  std::cout << "常数阶[n = 5时]\t\t\t --> f(n)：" << constant(5) << std::endl;
  std::cout << "线性阶[n = 5时]\t\t\t --> f(n)：" << linear(5) << std::endl;

  std::vector<int> nums;
  std::cout << "线性阶[nums = 5时]\t\t --> f(n)：" << arrayTraversal(nums)
            << std::endl;

  std::cout << "平方阶[n = 5时]\t\t\t --> f(n)：" << quadratic(5) << std::endl;

  for (int i = 5; i > 0; --i) {
    nums.push_back(i);
  }
  // std::cout << nums.size();
  std::cout << "平方阶[nums = 5时]\t\t --> f(n)：" << bubbleSort(nums)
            << std::endl;

  std::cout << "指数阶-细胞分裂次数[n = 5时]\t --> f(n)：" << exponential(5)
            << std::endl;

  int count = 0;
  std::cout << "指数阶-递归次数[n = 5时]\t --> f(n)：" << expRecur(5, count)
            << std::endl;
  std::cout << "对数阶-循环次数[n = 5时]\t --> f(n)：" << logarithmic(5)
            << std::endl;
  std::cout << "对数阶-递归次数[n = 5时]\t --> f(n)：" << logRecur(5)
            << std::endl;
  std::cout << "线性对数阶-递归次数[n = 5时]\t --> f(n)：" << linearRecur(5)
            << std::endl;
  std::cout << "阶乘阶-递归次数[n = 5时]\t --> f(n)：" << factorialRecur(5)
            << std::endl;

  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();

  return 0;
}

int constant(int n) {
  int count = 0;
  int size = 100000;

  for (int i = 0; i < size; ++i) {
    ++count;
  }

  return count;
}

int linear(int n) {
  int count = 0;

  for (int i = 0; i < n; ++i) {
    ++count;
  }

  return count;
}

int arrayTraversal(std::vector<int>& nums) {
  int count = 0;

  for (int num : nums) {
    ++count;
  }

  return count;
}

int quadratic(int n) {
  int count = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ++count;
    }
  }

  return count;
}

int bubbleSort(std::vector<int>& nums) {
  int count = 0;

  for (int i = nums.size() - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] > nums[j + 1]) {
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;

        count += 3;
      }
    }
  }

  return count;
}

// 模拟计算细胞分裂，经历n轮时，计算机运行的次数count；
int exponential(int n) {
  int count = 0;
  int base = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < base; ++j) {
      ++count;
    }

    base *= 2;
  }

  return count;
}

int expRecur(int n, int& count) {
  if (n <= 0) {
    return -1;
  }

  ++count;
  if (1 == n) {
    return 1;
  }

  return expRecur(n - 1, count) + expRecur(n - 1, count) + 1;
}

int logarithmic(int n) {
  int count = 0;

  while (n > 1) {
    n /= 2;
    ++count;
  }

  return count;
}

int logRecur(int n) {
  if (n <= 1) {
    return 0;
  }

  return logRecur(n / 2) + 1;
}

int linearRecur(int n) {
  if (n <= 1) {
    return 1;
  }

  int count = linearRecur(n / 2) + linearRecur(n / 2);

  for (int i = 0; i < n; ++i) {
    ++count;
  }

  return count;
}

int factorialRecur(int n){
  if (0 == n) {
    return 1;
  }

  int count = 0;
  
  // 从1个分裂出n个
  for (int i = 0; i < n; ++i) {
    count += factorialRecur(n - 1);
  }

  return count;
}