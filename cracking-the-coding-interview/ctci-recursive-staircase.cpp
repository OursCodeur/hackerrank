#include <iostream>

using namespace std;

int memo[37];

int steps(int n) {
	if (n < 0) return 0;
	if (memo[n]) return memo[n];
	else return memo[n] = steps(n - 1) + steps(n - 2) + steps(n - 3);
}

int main() {
	int s;
	int n;
	memo[0] = 1;
	cin >> s;
	while (s--) {
		cin >> n;
		cout << steps(n) << endl;
	}
	return 0;
}
