#include <iostream>
#include <deque>
#include <cctype>
using namespace std;

class BigInt {
    static const int base = 10;
    public:
    deque<int> digits;
    BigInt() {
    }
    BigInt operator +(BigInt x) {
        BigInt c;

        // add
        auto di = digits.begin(), xi = x.digits.begin(), end = digits.end();
        for (; di != end && xi != x.digits.end(); di++, xi++)
            c.digits.push_back(*di + *xi);

        // set rest
        if (di == digits.end()) {
            di = xi;
            end = x.digits.end();
        }
        for (; di != end; di++)
            c.digits.push_back(*di);

        // nomalize
        int carry = 0;
        for (int i = 0; i < c.size(); i++) {
            c.digits[i] += carry;
            carry = c.digits[i] / base;
            c.digits[i] %= base;
        }
        if (carry)
            c.digits.push_back(carry);

        return c;
    }
    int size() {
        return digits.size();
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
        for (BigInt a, b, c; n-- && cin >> a >> b;) {
            c = a + b;
            if (c.size() <= 80)
                cout << c << endl;
            else
                cout << "overflow" << endl;
        }

    return 0;
}
