//#include <bits/stdc++.h>
#include <math.h>
#include <functional>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
// https://blog.csdn.net/ywcpig/article/details/52757764
// https://codeforces.com/blog/entry/46881
// http://stlighter.github.io/2016/09/15/Round-B-APAC-Test-2017-%E9%A2%98%E8%A7%A3/

const long long MOD = 1000000007;

int fastExp(int base, int exp, int mod)
{
    long long result = 1;
    if (1 & exp)
        result = base;
    while (1) {
        if (!exp)
            break;
        exp >>= 1;
        base = (base * base) % mod;
        if (exp & 1)
            result = (result * base) % mod;
    }
    return result;
}


int CountNumberOfPairs(int a, int b, long long n, int k)
{
    // TODO: implement this method to determine the number of pairs modulo
    // 10^9+7
    int number_of_pairs = 0;
    unordered_map<long long, long long> mymap;

    long long cnt = n / k;
    long long om = n % k;

    for (long long i = 1; i <= min(n, (long long)k); i++) {
        long long tmp = fastExp(i, a, k);
        if (i <= om) {
            mymap[tmp] += (cnt + 1) % MOD;
        } else {
            mymap[tmp] += cnt % MOD;
        }
        mymap[tmp] %= MOD;
    }

    for (long long i = 1; i <= min(n, (long long)k); ++i) {
        long long tmp = (k - fastExp(i, b, k)) % k;
        if (i <= om) {
            if (fastExp(i, a, k) == tmp) {
                number_of_pairs +=
                    mymap[tmp] * ((cnt + 1) % MOD) - (cnt + 1) % MOD;
                number_of_pairs = (number_of_pairs % MOD + MOD) % MOD;
            } else {
                number_of_pairs += mymap[tmp] * ((cnt + 1) % MOD);
                number_of_pairs %= MOD;
            }
        } else {
            if (fastExp(i, a, k) == tmp) {
                number_of_pairs += mymap[tmp] * (cnt % MOD) - cnt % MOD;
                number_of_pairs = (number_of_pairs % MOD + MOD) % MOD;
            } else {
                number_of_pairs += mymap[tmp] * (cnt % MOD);
                number_of_pairs %= MOD;
            }
        }
    }

    return number_of_pairs;
}

int main()
{
    int test_case_count;
    cin >> test_case_count;
    int a, b, k;
    long long n;
    for (int tc = 1; tc <= test_case_count; ++tc) {
        cin >> a >> b >> n >> k;
        cout << "Case #" << tc << ": " << CountNumberOfPairs(a, b, n, k)
             << "\n";
    }
    return 0;
}
