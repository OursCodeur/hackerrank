#include <vector>
#include <iostream>

using namespace std;

bool is_balanced(string expression) {
	vector<char> stack;
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(') {
			stack.push_back(expression[i]);
		}
		else {
			if (stack.size() == 0) {
				return false;
			}
			char bk = stack.back();
			stack.pop_back();
			if ((bk == '{' && expression[i] != '}') || (bk == '[' && expression[i] != ']') || (bk == '(' && expression[i] != ')')) {
				return false;
			}
		}
	}
	return (stack.size() == 0);
}

int main() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		string expression;
		cin >> expression;
		bool answer = is_balanced(expression);
		if (answer) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
