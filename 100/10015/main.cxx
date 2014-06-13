#include <iostream>
#include <vector>
using namespace std;

int symbol_to_index(char &s)
{
    switch(s) {
    case 'S' : return 0;
    case 'H' : return 1;
    case 'C' : return 2;
    case 'D' : return 3;
    }
}

char index_to_symbol(int &i)
{
    switch(i) {
    case 0 : return 'S';
    case 1 : return 'H';
    case 2 : return 'C';
    case 3 : return 'D';
    }
}

int main()
{
    vector<vector <bool>> cards(4, vector<bool>(14, false));
    int n, x;
    char symbol;

    cin >> n;
    for (;cin >> symbol >> x && n; n--)
        cards[symbol_to_index(symbol)][x] = true;

    for (int i = 0; i < cards.size(); i++) {
        char s = index_to_symbol(i);
        for (int j = 1; j < cards[i].size(); j++)
            if (!cards[i][j])
                cout << s << " " << j << endl;
    }


    return 0;
}
