#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	string t, p;
	cin >> t >> p;
	regex r("(?=" + p + ").");
	for (auto i = sregex_iterator(t.begin(), t.end(), r), e = sregex_iterator(); i != e; ++i)
		cout << (*i).position() << endl;
}

/* vim: set ts=4 noet: */
