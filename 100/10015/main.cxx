#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main()
{
    // init cards
    const char symbols[] = "SHCD";
    map<char, vector <bool>> cards;
    for(auto c : symbols)
        cards[c] = vector<bool>(14, false);

    // input
    int n, x;
    char symbol;
    cin >> n;
    for (;cin >> symbol >> x && n; n--)
        cards[symbol][x] = true;

    // output
    for (int i = 0; i < 4; i++) {
        char symbol = symbols[i];
        for (int j = 1; j < cards[symbol].size(); j++)
            if (!cards[symbol][j])
                cout << symbol << " " << j << endl;
    }

    return 0;
}
