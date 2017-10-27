#include <bits/stdc++.h>

using namespace std;

long aVeryBigSum(vector <long> ar) {
	long res = 0;
	for (long& num : ar)
		res += num;
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<long> ar(n);
	for (int ar_i = 0; ar_i < n; ar_i++) {
		cin >> ar[ar_i];
	}
	long result = aVeryBigSum(ar);
	cout << result << endl;
	return 0;
}
