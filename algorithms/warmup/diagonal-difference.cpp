#include <vector>
#include <iostream>

using namespace std;

int main() {
	int n;
	int res_d1 = 0;
	int res_d2 = 0;
	cin >> n;
	vector< vector<int> > a(n, vector<int>(n));
	for (int a_i = 0; a_i < n; a_i++) {
		for (int a_j = 0; a_j < n; a_j++) {
			cin >> a[a_i][a_j];
		}
	}

	for (int d_i = 0; d_i < n; d_i++) {
		res_d1 += a[d_i][d_i];
		res_d2 += a[d_i][n - 1 - d_i];
	}

	cout << abs(res_d1 - res_d2) << endl;

	return 0;
}
