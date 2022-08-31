//#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_map<char, vector<int> > dir;

struct Coordinate {
    int r;
    int c;
    Coordinate(int r, int c) : r(r), c(c) {}
};
Coordinate EndPosition(int N, int R, int C, int Sr, int Sc, string instructions)
{
    unordered_set <int> us[R + 1];
    dir['N'] = {-1, 0};
    dir['E'] = {0, 1};
    dir['S'] = {1, 0};
    dir['W'] = {0, -1};
    int cur_x = Sr;
    int cur_y = Sc;
    us[cur_x].insert(cur_y);
    for(auto i : instructions) {
        vector<int> delta = dir[i];
        cur_x = cur_x + delta[0];
        cur_y = cur_y + delta[1];
        if (cur_x <= 0 || cur_x > R || cur_y <= 0 || cur_y > C)
            continue;
        while (us[cur_x].find(cur_y) != us[cur_x].end()) {
                cur_x += delta[0];
                cur_y += delta[1];
        }
        us[cur_x].insert(cur_y);

    }
    return Coordinate(cur_x, cur_y);
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