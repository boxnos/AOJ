#include <iostream>
#include <string>
#include <regex>
using namespace std;

typedef sregex_iterator ri;

int main() {
	string t, p;
	cin >> t >> p;
	regex r("(?=" + p + ").");
	for (auto i = ri(t.begin(), t.end(), r), e = ri(); i != e; ++i)
		cout << (*i).position() << endl;
}

/* vim: set ts=4 noet: */
