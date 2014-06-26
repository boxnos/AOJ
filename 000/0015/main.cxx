#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class BigInt {
    static const int base = 10;
    vector<int> digits;
    public:
    BigInt() {
    }
    istream &read(istream &is) {
        digits.clear();
        cin.ignore();

        int s;
        while (s = cin.get(), isdigit(s))
            digits.push_back(s - '0');
        is.putback(s);

        return is;
    }
    ostream &write(ostream &os) {
        for (int x : digits)
            cout << x;
        return os;
    }
};

istream &operator>>(istream &is, BigInt &b) { return b.read(is); }
ostream &operator<<(ostream &os, BigInt &b) { return b.write(os); }

int main()
{
    for (int n; cin >> n;)
        for (BigInt a, b; n-- && cin >> a >> b;)
            cout << a << " " << b << endl;
    return 0;
}
