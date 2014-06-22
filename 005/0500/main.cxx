#include <iostream>
using namespace std;

struct Game {
    int a, b;
    Game() {
        a = 0;
        b = 0;
    }
    void score(int card_a, int card_b) {
        if (card_a > card_b)
            a += card_a + card_b;
        else if (card_a < card_b)
            b += card_a + card_b;
        else {
            a += card_a;
            b += card_b;
        }
    }
    void board() {
        cout << a << " " << b << endl;
    }
};

int main()
{
    for (int n; cin >> n && n;) {
        Game game;
        for (int a, b; n-- && cin >> a >> b;)
            game.score(a, b);
        game.board();
    }

    return 0;
}
