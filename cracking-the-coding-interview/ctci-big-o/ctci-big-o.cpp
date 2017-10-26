#include <cmath>
#include <iostream>

using namespace std;

static bool is_prime(int i) {
	if (i == 1) return false;		// 1 isn't prime
	if (i == 2) return true;		// 2 is though
	if (i % 2 == 0) return false;		// Even numbers aren't prime

	int div = 3;				// No need to test even dividers either
	while (div <= sqrt(i)) {
		if (i%div == 0) {
			return false;
		}
		div = div + 2;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int i;
		cin >> i;
		if (is_prime(i))
		{
			cout << "Prime" << endl;
		}
		else {
			cout << "Not prime" << endl;
		}
	}
	return 0;
}
