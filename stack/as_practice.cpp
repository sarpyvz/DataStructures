#include "DLStack.h"
#include <functional>
#include <random>
#include <sstream>
#include <unordered_map>

template <typename T> T getRandom(T lower = 0, T upper = 100) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<T> dis(lower, upper);
  return dis(gen);
}

template <class T>
void pushRandomElements(DLStack<T> &S, int count, int lower = 0,
                        int upper = 100) {
  for (int i = 0; i < count; i++) {
    S.push(getRandom<T>(lower, upper));
  }
}

// Evaluate Reverse Polish Notation
int evaluateRPN(const std::vector<std::string> &tokens) {
  // YOUR SOLUTION SHOULD BE WRITE IN HERE
  DLStack operands;
  DLStack nums;
  int answer;
  int op1;
  int op2;
  // store operands in to a new stack and nums in a new stack
  while ( !tokens.isEmpty() ){
    if ( tokens.top() != int ){
        operands.push(tokens.top());
        tokens.pop();
    }
    else{
      nums.push(tokens.top());
      tokens.pop();
    }
  }

  nums.reverse();
  operands.reverse();

  // use top elements operand with top elemnt of nums stack
  while ( !nums.isEmpty()){
    op1 = nums.top();
    nums.pop();
    op2 = nums.top();
    answer     
  }


  
}

// Decode String with Nested Repeatitions
std::string decodeString(const std::string &s) {
  // YOUR SOLUTION SHOULD BE WRITE IN HERE
  
}
