#include <iostream>
#include <string>

using namespace std;
int color_game(const int N)
{
    int bot = N / 5 + (N % 5 != 0);
    return bot;
}

int main()
{
    int testcases;
    cin >> testcases;

    for (int t = 1; t <= testcases; ++t) {
        int cell_nums;
        cin >> cell_nums;
        cout << "Case #" << t << ": " << color_game(cell_nums) << "\n";
    }
    return 0;
}