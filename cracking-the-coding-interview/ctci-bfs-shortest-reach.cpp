#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int EDGE_WEIGHT = 6;

class Graph {
public:
	int v;
	vector<int> *adj;

	explicit Graph(int v) : v(v) {
		adj = new vector<int>[v];
	}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> shortest_reach(int start, int n) {
		vector<int> distance(n, -1);
		queue<int> q;
		vector<int>::iterator i;
		q.push(start);
		distance[start] = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (i = adj[cur].begin(); i != adj[cur].end(); ++i) {
				if (distance[*i] == -1) {
					q.push(*i);
					distance[*i] = distance[cur] + EDGE_WEIGHT;
				}
			}
		}
		return distance;
	}
};

int main() {
	int queries;
	cin >> queries;

	for (int t = 0; t < queries; t++) {

		int n;
		int m;
		cin >> n;
		// Create a graph of size n where each edge weight is 6: 
		Graph graph(n);
		cin >> m;
		// read and set edges
		for (int i = 0; i < m; i++) {
			int u;
			int v;
			cin >> u >> v;
			u--;
			v--;
			// add each edge to the graph
			graph.add_edge(u, v);
		}
		int startId;
		cin >> startId;
		startId--;
		// Find shortest reach from node s
		vector<int> distances = graph.shortest_reach(startId, n);

		for (int i = 0; i < distances.size(); i++) {
			if (i != startId) {
				cout << distances[i] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
