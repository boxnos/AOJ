#include <iostream>
#include <bitset>
using namespace std;

int main() {
    for(char c : {'N', 'S', 'E', 'W'}) {
        cout << c << ' ' << bitset<8>(c) << ' ' << bitset<3>(c) << endl;
        cout << (~c & 5 ? "NS" : "EW")  << endl;
    }
}
