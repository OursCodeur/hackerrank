#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> arr(5);
	long sum = 0;
	for (int arr_i = 0; arr_i < 5; arr_i++) {
		cin >> arr[arr_i];
	}

	for (long n : arr)
		sum += n;

	auto min_max = minmax_element(arr.begin(), arr.end());

	cout << sum - *min_max.second << ' ' << sum - *min_max.first << endl;

	return 0;
}
