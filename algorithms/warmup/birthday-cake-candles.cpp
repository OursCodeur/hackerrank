#include <bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(int n, vector <int> ar) {
	int tall = 0;
	int count = 1;
	for (int ar_i = 0; ar_i < n; ar_i++) {
		if (ar[ar_i] > tall) {
			count = 1;
			tall = ar[ar_i];
		}
		else if (ar[ar_i] == tall) {
			count++;
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int ar_i = 0; ar_i < n; ar_i++) {
		cin >> ar[ar_i];
	}
	int result = birthdayCakeCandles(n, ar);
	cout << result << endl;
	return 0;
}
