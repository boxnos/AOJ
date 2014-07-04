#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    if (v.size()) {
        os << v.front();
        for (auto vi = v.begin() + 1; vi != v.end(); vi++)
            os << " " << *vi;
    }
    return os;
}

struct Paper{

    vector<vector <int>> paper;

    Paper() {
        paper = vector<vector <int>>(10, vector<int>(10, 0));
    }

    void display() {
        for (auto line : paper)
            cout << line << endl;
    }

    void output() {
        int max_value = 0;
        int density_zero = 0;

        for (auto y : paper)
            for (auto x : y)
                if (x == 0)
                    density_zero++;
                else
                    max_value = max(max_value, x);
        cout << density_zero << endl;
        cout << max_value << endl;
    }

    void drop(int x, int y, int size)
    {
        switch (size) {
        case 3:
            put(x + 2, y);
            put(x, y + 2);
            put(x - 2, y);
            put(x, y - 2);
        case 2:
            put(x + 1, y + 1);
            put(x + 1, y - 1);
            put(x - 1, y + 1);
            put(x - 1, y - 1);
        case 1:
            put(x + 1, y);
            put(x, y + 1);
            put(x - 1, y);
            put(x, y - 1);
        }

        put(x, y);
    }

private:
    void put(int x, int y)
    {
        if (0 <= x && x < paper[0].size() &&
            0 <= y && y < paper.size())
            paper[y][x]++;
    }
};


int main()
{
    Paper paper;
    char comma;

    for (int x, y, size; cin >> x >> comma >> y >> comma >> size;)
        paper.drop(x, y, size);

    // paper.display();
    paper.output();

    return 0;
}
