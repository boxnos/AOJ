#include <iostream>
#include <regex>
using namespace std;

int main () {
	int n;
	string s;
	regex r("Hoshino");
	cin >> n;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		cout << regex_replace(s, r, "Hoshina") << endl;
	}
}


/* vim: set ts=4 noet: */
