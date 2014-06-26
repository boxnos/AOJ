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
    BigInt operator +(const BigInt x) const {
        BigInt res;

        // add
        auto di = digits.begin(), xi = x.digits.begin(), end = digits.end();
        for (; di != end && xi != x.digits.end(); di++, xi++)
            res.digits.push_back(*di + *xi);

        // set rest
        if (di == end) {
            di = xi;
            end = x.digits.end();
        }
        for (; di != end; di++)
            res.digits.push_back(*di);

        res.normalize();

        return res;
    }
    void normalize() {
        int carry = 0;
        for (int i = 0; i < size(); i++) {
            digits[i] += carry;
            carry = digits[i] / base;
            digits[i] %= base;
        }
        if (carry)
            digits.push_back(carry);
    }
    int size() const {
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
    ostream &write(ostream &os) const {
        for (auto di = digits.rbegin(); di != digits.rend(); di++)
            cout << *di;
        return os;
    }
};

istream &operator>>(istream &is, BigInt &b) { return b.read(is); }
ostream &operator<<(ostream &os, const BigInt &b) { return b.write(os); }

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
