#include <vector>
#include <iostream>

using namespace std;

int main() {
	int n;
	int swaps = 0;
	bool sorted = false;
	cin >> n;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}

	while (!sorted) {
		int local = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				local++;
				swaps++;
			}
		}
		sorted = (local == 0);
	}

	cout << "Array is sorted in " << swaps << " swaps." << endl;
	cout << "First Element: " << a[0] << endl;
	cout << "Last Element: " << a[n - 1] << endl;

	return 0;
}
