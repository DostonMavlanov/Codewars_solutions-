#include <string>
#include <stack>

bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c) {
  return (c >= '0' && c <= '9');
}

int getPrecedence(char c) {
  if (c == '+' || c == '-' ) {
    return 1;
  }
  else if (c == '*' || c == '/') {
    return 2;
  }
  else if (c == '^') {
    return 3;
  }
  else {
    return 0;
  }
}

std::string to_postfix(std::string infix) {
  std::string postfix;
  std::stack<char> operatorStack;
    
  for (char c : infix) {
    if (isOperand(c)) {
      postfix += c;
    }
    else if (isOperator(c)) {
      while (!operatorStack.empty() && getPrecedence(c) <= getPrecedence(operatorStack.top())) {
        postfix += operatorStack.top();
        operatorStack.pop();
      }
      operatorStack.push(c);
    }
    else if (c == '(') {
      operatorStack.push(c);
    }
    else if (c == ')') {
      while (!operatorStack.empty() && operatorStack.top() != '(') {
        postfix += operatorStack.top();
        operatorStack.pop();
      }
      operatorStack.pop();
    }
  }
  while (!operatorStack.empty()) {
    postfix += operatorStack.top();
    operatorStack.pop();
  }
  
  return postfix;
}