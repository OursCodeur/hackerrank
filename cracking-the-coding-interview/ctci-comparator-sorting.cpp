#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
	string name;
	int score;
};

bool quick_sort(Player p_1, Player p_2) {
	if (p_1.score > p_2.score) return true;
	if (p_1.score == p_2.score) return p_1.name < p_2.name;
	return false;
}

vector<Player> comparator(vector<Player> players) {
	sort(players.begin(), players.end(), quick_sort);
	return players;
}

int main() {

	int n;
	cin >> n;
	vector< Player > players;
	string name;
	int score;
	for (int i = 0; i < n; i++) {
		cin >> name >> score;
		Player p1;
		p1.name = name;
		p1.score = score;
		players.push_back(p1);
	}

	vector<Player > answer = comparator(players);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].name << " " << answer[i].score << endl;
	}
	return 0;
}
