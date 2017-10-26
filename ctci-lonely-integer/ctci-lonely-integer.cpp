#include <vector>
#include <iostream>

using namespace std;

int lonely_integer(vector < int > a) {
	int res = 0;
	// Since we know all elements are given in pairs except for the one we're 
	// looking for, using XOR on all elements will give away the single result
	for (int i = 0; i < a.size(); i++)
		res ^= a[i];
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	cout << lonely_integer(a) << endl;
	return 0;
}
