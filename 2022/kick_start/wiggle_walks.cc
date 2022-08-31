//#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Coordinate {
    int r;
    int c;
    Coordinate(int r, int c) : r(r), c(c) {}

    bool operator==(const Coordinate &coord) const
    {
        return (this->r == coord.r && this->c == coord.c);
    }

    struct HashFunction {
        size_t operator()(const Coordinate &coord) const
        {
            size_t r_hash = std::hash<int>()(coord.r);
            size_t c_hash = std::hash<int>()(coord.c);
            return r_hash ^ c_hash;
        }
    };
};

unordered_map<char, vector<int> > dir;

Coordinate EndPosition(int N, int R, int C, int Sr, int Sc, string instructions)
{
    Coordinate cur = Coordinate(Sr, Sc);
    unordered_map <Coordinate, bool, Coordinate::HashFunction> visited;
    dir['N'] = {-1, 0};
    dir['E'] = {0, 1};
    dir['S'] = {1, 0};
    dir['W'] = {0, -1};

    visited[cur] = true;
    for(auto i : instructions) {
        vector<int> delta = dir[i];
        cur.r = cur.r + delta[0];
        cur.c = cur.c + delta[1];
        if (cur.r <= 0 || cur.r > R || cur.c <= 0 || cur.c > C)
            continue;
        while(visited[cur]) {
            cur.r = cur.r + delta[0];
            cur.c = cur.c + delta[1];
        }
        visited[cur] = true;
    }
    return cur;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, R, C, Sr, Sc;
        string instructions;
        cin >> N >> R >> C >> Sr >> Sc >> instructions;
        Coordinate ans = EndPosition(N, R, C, Sr, Sc, instructions);
        cout << "Case #" << t << ": " << ans.r << " " << ans.c << endl;
    }
}
