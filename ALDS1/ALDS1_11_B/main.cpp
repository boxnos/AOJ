#include <iostream>
#include <map>
#include <set>
using namespace std;

struct graph {
	struct node {set<int> v; int d = 0, f;};
	map<int, node> nodes;
	int count = 1;

	void read_all() {
		int n, id, k, v;
		cin >> n;
		while (n--) {
			cin >> id >> k;
			if (k)
				while (k--) {
					cin >> v;
					nodes[id].v.insert(v);
				}
			else
				nodes[id] = {};
		}
	}
	void traverse(int id) {
		if (nodes[id].d)
			return;
		nodes[id].d = count++;
		for (int x: nodes[id].v)
			traverse(x);
		nodes[id].f = count++;
	}
	void traverse() {
		for (auto n: nodes)
			traverse(n.first);
	}
	void display_all() {
		for (auto n: nodes)
			cout << n.first << " " << n.second.d << " " << n.second.f << endl;

	}
};

int main() {
	graph g;
	g.read_all();
	g.traverse();
	g.display_all();
}

/* vim: set ts=4 noet: */
