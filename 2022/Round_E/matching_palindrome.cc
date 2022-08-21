#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case(int test_case) {
    int N;
    scanf( "%d", &N);

    string input_str;
    cin >> input_str;

    cout << "Case #" << test_case << ": ";
    cout << input_str <<"\n";
}

int main() {
    int tests;
    scanf( "%d", &tests);

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        cout << flush;
    }
}
