#include <iostream>
#include <stack>
#include <sstream>
#include<string>

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
int main() {
  string s;
  getline(cin, s);
  string ans = rpn(s);
  cout << ans;
  return 0;
}
