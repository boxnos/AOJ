#include <iostream>
using namespace std;

struct Game {
    int a, b;
    Game() {
        a = 0;
        b = 0;
    }
    void score(const string &card_a, const string &card_b) {
        if (card_a > card_b)
            a += 3;
        else if (card_a < card_b)
            b += 3;
        else {
            a += 1;
            b += 1;
        }
    }
    void board() const {
        cout << a << " " << b << endl;
    }
};

int main()
{
    Game game;
    int n;
    cin >> n;

    for (string a, b; n-- && cin >> a >> b;)
        game.score(a, b);

    game.board();

    return 0;
}
