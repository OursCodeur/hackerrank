#include <bits/stdc++.h>

using namespace std;

int main() {
	int h;
	int m;
	int s;
	char dots;
	char ampm;

	cin >> h >> dots >> m >> dots >> s >> ampm >> dots;
	h = (ampm == 'A') ? (h == 12 ? 0 : h) : (h == 12 ? 12 : h + 12);

	cout << setw(2) << setfill('0') << h << ":"
		<< setw(2) << setfill('0') << m << ":"
		<< setw(2) << setfill('0') << s << endl;

	return 0;
}
