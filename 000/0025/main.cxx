#include <iostream>
#include <vector>
using namespace std;

struct HitAndBlow
{
    vector<int> cards;

    HitAndBlow(){
        cards = vector<int>(4);
    }

    void board(const HitAndBlow &other) const {
        int hit = 0, blow = 0;
        for (int i = 0; i < cards.size(); i++) {
            if (cards[i] == other.cards[i]) {
                hit++;
                continue;
            }
            for (int j = 0; j < cards.size(); j++)
                if (cards[i] == other.cards[j]) {
                    blow++;
                    break;
                }
        }
        cout << hit << " " << blow << endl;
    }
};

istream &operator >> (istream &is, HitAndBlow &g)
{
    for (int i = 0; i < g.cards.size(); i++)
        is >> g.cards[i];
    return is;
}

int main()
{
    for (HitAndBlow braker, maker; cin >> braker >> maker;)
        maker.board(braker);

    return 0;
}
