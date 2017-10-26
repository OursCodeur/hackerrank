#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

void find_pairs(int m, vector<int> ice_creams) {
	int n = ice_creams.size();
	bool done = false;
	int sny = 0;
	int jny = 0;

	// Using a BST here was a bit overkill...

	for (int i = 1; i < n; i++) {
		if (done) { break; }
		for (int j = 1; j < n; j++) {
			if (i != j && ice_creams[i] + ice_creams[j] == m) {
				sny = i;
				jny = j;
				done = true;
				break;
			}
		}
	}
	cout << min(sny, jny) << " " << max(sny, jny) << endl;
}


int main()
{
	int t;
	cin >> t;
	while (t--) {
		int m;
		int n;
		cin >> m >> n;
		vector<int> ice_creams(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> ice_creams[i];
		}
		find_pairs(m, ice_creams);
	}
	return 0;
}
