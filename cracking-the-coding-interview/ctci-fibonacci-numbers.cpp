#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {

	static vector<int> memo;

	if (n <= 1) {
		return n;
	}
	else if (n >= memo.size()) {
		memo.resize(n + 1);
	}

	if (memo[n] == 0) {
		memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return memo[n];
}

int main() {
	int n;
	cin >> n;
	cout << fibonacci(n);
	return 0;
}
