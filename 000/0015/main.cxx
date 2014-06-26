#include <iostream>
#include <deque>
#include <cctype>
using namespace std;

class BigInt {
    static const int base = 10;
    deque<int> digits;
    public:
    BigInt() {
    }
    istream &read(istream &is) {
        digits.clear();
        cin.ignore();

        int s;
        while (s = cin.get(), isdigit(s))
            digits.push_front(s - '0');
        is.putback(s);

        return is;
    }
    ostream &write(ostream &os) {
        for (auto di = digits.rbegin(); di != digits.rend(); di++)
            cout << *di;
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
