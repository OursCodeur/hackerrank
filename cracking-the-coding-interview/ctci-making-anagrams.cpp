#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
	unordered_map<char, int> umap;
	int common_chars = 0;
	for (char& c : a) {
		// Build a frequency histogram
		umap[c]++;
	}
	for (pair<char, int> res : umap) {
		// Check for results matching the histogram
		int b_count = count(b.begin(), b.end(), res.first);
		if (b_count > 0) {
			// And count the frequency twice
			common_chars += min(b_count, res.second) * 2;
		}
	}
	return (a.length() + b.length() - common_chars);
}

int main() {
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << number_needed(a, b) << endl;
	return 0;
}