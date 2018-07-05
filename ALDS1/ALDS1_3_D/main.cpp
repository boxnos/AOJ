#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

template<typename T>
T f(T s, T e, int &A, vi &v) {
	for (T i = s + 1; i != e; i++)
		if (*i > *s)
			s = i;
		else if (*i == *s) {
			int l = 0;
			for (T j = s; j != i; j++)
				l +=  *s * 2 - *j - *(j + 1);
			if (l) {
				v.push_back(l/2);
				A += l/2;
			}
			s = i;
		}
	return s;
}

int main()
{
	char c;
	int h = 0, A = 0;
	vi H = {h}, L, M;

	while (cin >> c)
		H.push_back(c == '/' ? ++h : c == '_' ? h : --h);

	auto e = f(H.begin(), H.end(), A, L);
	f(H.rbegin(), H.rend() - distance(H.begin(), e), A, M);

	reverse(M.begin(), M.end());
	std::copy(M.begin(),M.end(),std::back_inserter(L));
	
	cout << A << endl << L.size();
	for (int &x: L)
		cout << " " << x;
	cout << endl;
}

/* vim: set ts=4 noet: */
