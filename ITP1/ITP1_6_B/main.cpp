#include <iostream>
#include <vector>
using namespace std;

enum suits { S, H, C, D };

int main(void)
{
    int n, rank;
    char suit;
    vector<bool> cards(52, true);

    cin >> n;
    while (cin >> suit >> rank && n--) {
        int s;
        switch (suit) {
        case 'S': s = S; break;
        case 'H': s = H; break;
        case 'C': s = C; break;
        case 'D': s = D; break;
        }
        cards[s * 13 + rank - 1] = false;
    }


    for (int i = 0; i < cards.size(); i++)
        if (cards[i]) {
            switch (i / 13) {
            case S: cout << 'S'; break;
            case H: cout << 'H'; break;
            case C: cout << 'C'; break;
            case D: cout << 'D'; break;
            }
            cout  << " " << i % 13 + 1 << endl;
        }

    return 0;
}
