#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

	int m;
	int n;
	cin >> m >> n;
	vector<string> magazine(m);
	vector<string> ransom(n);

	for (int magazine_i = 0; magazine_i < m; magazine_i++) {
		cin >> magazine[magazine_i];
	}
	for (int ransom_i = 0; ransom_i < n; ransom_i++) {
		cin >> ransom[ransom_i];
	}

	unordered_map<string, int> umap;
	bool valid = true;

	for (string& s : magazine) {
		umap[s]++;
	}

	for (string& s : ransom) {
		if ((umap.find(s) == umap.end()) || umap[s] == 0) {
			valid = false;
			break;
		}
		umap[s]--;
	}

	valid ? cout << "Yes\n" : cout << "No\n";

	return 0;
}