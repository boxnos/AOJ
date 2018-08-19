#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct graph {
	struct node {vector<int> v; int d = -1;};
	map<int, node> nodes;

	void read_all() {
		int n, id, k, v;
		cin >> n;
		while (n--) {
			cin >> id >> k;
			if (k)
				while (k--) {
					cin >> v;
					nodes[id].v.push_back(v);
				}
			else
				nodes[id].v = {};
		}
	}
	void traverse(int id) {
		nodes[id].d = 0;
		queue<int> q;
		q.push(id);
		while (!q.empty()) {
			node &n = nodes[q.front()];
			q.pop();
			for (int x: n.v) {
				if (nodes[x].d != -1)
					continue;
				else
					nodes[x].d = n.d + 1;
				q.push(x);
			}
		}
	}
	void display_all() {
		for (auto &n: nodes)
			cout << n.first << " " << n.second.d << endl;
	}
};

int main() {
	graph g;
	g.read_all();
	g.traverse(1);
	g.display_all();
}

/* vim: set ts=4 noet: */
