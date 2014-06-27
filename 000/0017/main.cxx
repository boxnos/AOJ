#include <iostream>
#include <sstream>
using namespace std;

int mod(int a, int b)
{
    int res = a % b;
    return (res >= 0) ? res : b + a;
}

int attack(string line)
{
    static const string cmp[] = {"the", "this", "that"};
    istringstream iss(line);

    for (string word; iss >> word;) {
        char first = word[0];
        for (string c: cmp) {
            int i = 1;
            for (; i < c.size() && i < word.size(); i++)
                if (mod(c[i] - 't', 26) != mod(word[i] - first, 26))
                    break;
            if (i == c.size())
                return mod('t' - first, 26);
        }
    }

    return 0;
}

inline int rotN(int x, int n)
{
    if (isalpha(x))
        return (x - 'a' + n) % 26 + 'a';
    else
        return x;
}

int main()
{
    int rot;
    string line;

    while (getline(cin, line)) {

        rot = attack(line);

        for (auto x : line)
            cout << (char) rotN(x, rot);

        cout << endl;
    }

    return 0;
}
