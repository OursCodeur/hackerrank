#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int n;
	int pos = 0;
	int neg = 0;
	int nul = 0;
	cin >> n;
	vector<int> arr(n);

	cout << fixed << setprecision(6);

	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
	}

	for (int& i : arr) {
		if (i > 0) { pos++; }
		else if (i < 0) { neg++; }
		else { nul++; }
	}

	cout << (float)pos / n << endl;
	cout << (float)neg / n << endl;
	cout << (float)nul / n << endl;

	return 0;
}
