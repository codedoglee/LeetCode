/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are+,-,*,/. Each operand may be an integer or another expression.
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

static int stringToInt(std::string str) {
	std::stringstream ss;
	ss << str;
	int res;
	ss >> res;
	return res;
}

class Solution {
public:
	int evalRPN(std::vector<std::string> &tokens) {
		if (tokens.size() == 0) {
			return 0;
		}

		std::stack<int> stk;

		for (unsigned int i = 0; i < tokens.size(); ++i) {
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
				int b = stk.top();
				int a = stk.top();
				stk.pop();
				stk.pop();
				if (tokens[i] == "+") {
					stk.push(a + b);
				}
				if (tokens[i] == "-") {
					stk.push(a - b);
				}
				if (tokens[i] == "*") {
					stk.push(a * b);
				}
				if (tokens[i] == "/") {
					stk.push(a / b);
				}
			} else {
				stk.push(stringToInt(tokens[i]));
			}
		}
		return stk.top();
	}
};
