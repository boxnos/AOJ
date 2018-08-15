#include <iostream>
using namespace std;
int main(){
	int n, t, a = 1, b = 1;
	cin >> n;
	while (n-- > 1)
		t = a, a = b, b += t;
	cout << b << endl;
}
/* vim: set ts=4 noet: */
