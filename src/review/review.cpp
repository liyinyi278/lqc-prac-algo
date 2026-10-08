#include <iostream>
#include <stack>
int forLoopStack(int n) ;

int main(){
  std::cout << "利用循环+stack库模拟递归计算：1 + …… + " << 100 << " = " << forLoopStack(100) << std::endl;
  
  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}

int forLoopStack(int n) {
  if (n <= 0) {
    return -1;
  }

  std::stack<int> stack;
  int result = 0;

  for (int i = n; i > 0; --i) {
    stack.push(i);
  }

  while (!stack.empty()) {
    result += stack.top();
    stack.pop();
  }

  return result;
}