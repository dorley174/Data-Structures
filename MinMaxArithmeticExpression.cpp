#include <iostream>
#include <stack>
#include <sstream>
#include<string>
#include <queue>

using namespace std;
bool isOperator(const string & token) {
  return token == "+" || token == "-" || token == "*" || token == "/" || token == "min" || token == "max";
}
bool isDigit(const string & token) {
  return token <= "9" && token >= "0";
}
int getPriority(const string & token) {
  if (token == "+" || token == "-") return 1;
  if (token == "*" || token == "/") return 2;
  if (token == "min" || token == "max") return 3;
  return 0;
}
int min(int a, int b) {
  return (a > b ? b : a);
}
int max(int a, int b) {
  return (a > b ? a : b);
}
string rpn(string input) {
  string postfix = "";
  string output = "", token;
  stack < string > s;
  istringstream iss(input);
  while (iss >> token) {
    if (isDigit(token)) {
      postfix += token;
      postfix += " ";
    } else if (isOperator(token)) {
      while (!s.empty() && getPriority(s.top()) >= getPriority(token)) {
        postfix += s.top();
        postfix += " ";
        s.pop();
      }
      s.push(token);
    } else if (token == "(") {
      s.push(token);
    } else if (token == ")") {
      while (!s.empty() && s.top() != "(") {
        postfix += s.top();
        postfix += " ";
        s.pop();
      }
      s.pop();
    } else if (token == ",") {
      while (s.top() != "(") {
        postfix += s.top();
        postfix += " ";
        s.pop();
      }
    }
  }
  while (!s.empty()) {
    postfix += s.top();
    postfix += " ";
    s.pop();
  }
  return postfix;
}
int calculate(string input) {
  queue < string > queue;
  stack < int > numbers;
  int a, b;
  istringstream iss(input);
  string token;
  while (iss >> token) {
    queue.push(token);
  }
  while (queue.size() != 0) {
    if (!isOperator(queue.front())) {
      numbers.push(stoi(queue.front()));
      queue.pop();

    } else {
      a = numbers.top();
      numbers.pop();
      b = numbers.top();
      numbers.pop();
      if (queue.front() == "min") {
        numbers.push(min(a, b));
        queue.pop();
      } else if (queue.front() == "max") {
        numbers.push(max(a, b));
        queue.pop();
      } else if (queue.front() == "+") {
        numbers.push(a + b);
        queue.pop();
      } else if (queue.front() == "-") {
        numbers.push(b - a);
        queue.pop();
      } else if (queue.front() == "*") {
        numbers.push(a * b);
        queue.pop();
      } else {
        numbers.push(b / a);
        queue.pop();
      }

    }
  }
  return numbers.top();
}
int main() {
  string s, token;
  getline(cin, s);
  string ans = rpn(s);
  cout << calculate(ans);
  return 0;

}
