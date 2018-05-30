#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;

	while (cin >> s && s != "-") {
		int m, h;
		for (cin >> m; m && cin >> h; m--)
			s = s.substr(h) + s.substr(0, h);
		cout << s << endl;
	}

	return 0;
}
