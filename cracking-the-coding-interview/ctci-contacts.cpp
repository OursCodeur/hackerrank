#include <iostream>

using namespace std;

struct Node {
	Node* next[26];
	bool leaf;
	int total;
	Node() {
		for (int i = 0; i < 26; i++) { next[i] = NULL; }
		leaf = false;
		total = 0;
	}
};

Node* head = new Node();

void add(string s) {
	int n = s.size();
	int i = 0;

	Node* current = head;

	while (i < n) {
		int el = s[i] - 'a';
		if (current->next[el] == NULL) {
			Node* temp = new Node();
			current->next[el] = temp;
		}
		current = current->next[el];
		current->total = current->total + 1;
		i++;
	}

	current->leaf = true;
}

int find(string s) {
	int n = s.size();
	int i = 0;

	Node* current = head;

	while (i < n) {
		int el = s[i] - 'a';
		if (current->next[el] == NULL) { return 0; }
		current = current->next[el];
		i++;
	}

	if (current == NULL) {
		return 0;
	}

	return current->total;
}

int main() {
	int n;
	cin >> n;
	for (int a0 = 0; a0 < n; a0++) {
		string command;
		string contact;
		cin >> command >> contact;
		if (command == "add") { add(contact); }
		else if (command == "find") { cout << find(contact) << endl; }
	}
	return 0;
}