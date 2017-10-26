#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> a;

	cout << fixed << setprecision(1);

	for (int a_i = 0; a_i < n; a_i++) {

		int t_i;
		float med;
		cin >> t_i;

		// You could insert + sort each time but it's way slower !
		a.insert(upper_bound(a.begin(), a.end(), t_i), t_i);

		if (a_i % 2 == 0) {
			med = (float)a[a_i / 2];
		}
		else {
			med = (float)(a[(a_i - 1) / 2] + a[(a_i + 1) / 2]) / 2;
		}

		cout << med << endl;
	}
	return 0;
}
