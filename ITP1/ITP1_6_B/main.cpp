#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, rank;
    char suit;
    string suits = "SHCD";
    map<char, vector<bool>> cards;

    for (int i = 0; i < suits.size(); i++)
        cards[suits[i]] = vector<bool>(13, true);

    cin >> n;
    while (cin >> suit >> rank && n--)
        cards[suit][rank -1 ] = false;

    for (int i = 0; i < suits.size(); i++ )
        for (int j = 0; j < 13; j++)
            if (cards[suits[i]][j])
                cout << suits[i] << " " << j + 1 << endl;

    return 0;
}
