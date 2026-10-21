#include <iostream>
#include <stack>
int forLoopStack(int n) ;

int main(){
  std::cout << "1 到 " << 5 << " 的和是：" << forLoopStack(5) << std::endl;
  
  std::cout << std::endl;
  std::cout << "按回车键退出...";
  std::cin.get();
  
  return 0;
}

int forLoopStack(int n) {
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