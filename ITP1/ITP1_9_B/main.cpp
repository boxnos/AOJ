#include <iostream>
#include <string>
using namespace std;

template <typename T> T bind() {T x; cin >> x; return x;}

int main()
{
	string s;

	while (cin >> s && s != "-") {
		for (int m = bind<int>(), h; m && cin >> h; m--)
			s = s.substr(h) + s.substr(0, h);
		cout << s << endl;
	}

	return 0;
}
