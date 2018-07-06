#include <iostream>
#include <stack>
#include <deque>
using namespace std;

struct p {int f; int s;};

int main()
{
	char c;
	int A = 0;
	deque<p> L;
	stack<int> s;

	for (int i = 0; cin >> c; i++)
		if (c == '\\')
			s.push(i);
		else if (c == '/' && !s.empty()) {
			int j = s.top(), a = i - j;
			s.pop();
			A += a;
			for (; !L.empty() && L.back().f > j; L.pop_back())
				a += L.back().s;
			L.push_back({j, a});
		}
	
	cout << A << endl << L.size();
	for (p x: L)
		cout << " " << x.s;
	cout << endl;
}

/* vim: set ts=4 noet: */
