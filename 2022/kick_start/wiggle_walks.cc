//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <functional>
using namespace std;

struct Coordinate {
    int r;
    int c; 
    Coordinate(int r, int c) : r(r), c(c) {}

    bool operator==(const Coordinate& coord) const {
        return (this->r == coord.r && this->c == coord.c);
    }

    struct HashFunction {
        size_t operator()(const Coordinate& coord) const {
            size_t r_hash = std::hash<int>()(coord.r);
            size_t c_hash = std::hash<int>()(coord.c);
            return r_hash ^ c_hash;
        }
    };
};

Coordinate EndPosition(int N,
                           int R,
                           int C,
                           int Sr,
                           int Sc,
                           string instructions)
{
    Coordinate pos = Coordinate(Sr, Sc);
    unordered_set<Coordinate, Coordinate::HashFunction> visited;
    unordered_map< char, pair<int,int> > dir;
    dir['N'] = make_pair(-1, 0);
    dir['E'] = make_pair(0, 1);
    dir['S'] = make_pair(1,0);
    dir['W'] = make_pair(0,-1);
    int i = 0;
    visited.insert(pos);
    while(i < N) {
        char c = instructions[i];
        int x = pos.r + dir[c].first;
        int y = pos.c + dir[c].second;
        if(x <= 0 || x > R || y <= 0 || y > C)
            continue;
        Coordinate newp = Coordinate(x, y);
        //cout << newp.r <<"," << newp.c << endl;
        if(!visited.count(newp)) {
            i++;
            visited.insert(newp);
        }
        pos = newp;
    }
    return pos;
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
