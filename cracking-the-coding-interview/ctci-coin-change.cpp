#include <vector>
#include <iostream>

using namespace std;

long long make_change(vector<int> coins, int money) {
	vector<long long> results;
	results.reserve(money + 1);
	for (int i = 0; i <= money; i++) { results.push_back(0); }
	results[0] = 1;

	// For the theory behind this, take a look at ONeill Code's video
	// on the Coin Change Problem here : https://www.youtube.com/watch?v=jaNZ83Q3QGc

	for (int coin_amount : coins) {
		for (long long sum = coin_amount; sum <= money; sum++) {
			results[sum] += results[sum - coin_amount];
		}
	}

	return results[money];
}

int main() {
	int n;
	int m;
	cin >> n >> m;
	vector<int> coins(m);
	for (int coins_i = 0; coins_i < m; coins_i++) {
		cin >> coins[coins_i];
	}
	cout << make_change(coins, n) << endl;
	return 0;
}
