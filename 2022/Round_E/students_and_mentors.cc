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

int binary_search(vector<int> arr, int target) {
    // right_bound/upper bound
    int left = 0;
    int right = arr.size();
    int bound_idx = -1;
    while(left < right) {
        int mid = left + (right -left) / 2;
        if(arr[mid] <= target) { //Rj <= 2 * Ri
            left = mid + 1;
            bound_idx = mid;
        } else {
            right = mid;
        }
    }
    return bound_idx;
}

void run_case(int test_case) {
    int N;
    cin >> N;
    vector<int> rating(N);

    for(int i = 0; i < N; i++) {
        cin >> rating[i];
    }

    vector<int> sorted = rating;
    sort(sorted.begin(), sorted.end());
    vector<int> mentor;

    for (auto r:rating) {
        int idx = binary_search(sorted, 2 * r);
        if (sorted[idx] != r) {
            mentor.push_back(sorted[idx]);
        } else if (idx == 0) {// at smallest one can not be a mentor
            mentor.push_back(-1);
        } else if(sorted[idx] == r){// Note that a mentor can even have a rating that is lower or equal to their mentee's rating.
            mentor.push_back(sorted[idx - 1]);
        }
    }

    cout << "Case #" << test_case << ": ";
    output_vector(mentor);
}
/*
3
3
2000 1500 1900
5
1000 600 1000 2300 1800
2
2500 1200

Case #1: 1900 2000 2000
Case #2: 1800 1000 1800 1800 2300
Case #3: 1200 -1

*/
int main() {
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        cout << flush;
    }
}
