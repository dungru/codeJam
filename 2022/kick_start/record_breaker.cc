//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int NumberOfRecordBreakingDays(int numberOfDays, vector<int> visitors)
{
    // TODO: Complete this function to get the number of record breaking days
    stack<int> stk;
    if(numberOfDays == 1)
        return 1;
    int ans = 0;
    if(visitors[0] > visitors[1])
        ans++;
    stk.push(visitors[0]);

    for(int i = 1; i < numberOfDays; i++) {
        if(i + 1 < numberOfDays && visitors[i] > stk.top() && visitors[i] > visitors[i+1]) {
            ans++;
            stk.push(visitors[i]);
        } else if(i == numberOfDays - 1 && visitors[i] > stk.top()) {
            ans++;
        }
    }
    
    return ans;
}

int main()
{
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;
        vector<int> V(N);
        for (int i = 0; i < N; ++i) {
            cin >> V[i];
        }
        cout << "Case #" << tc << ": " << NumberOfRecordBreakingDays(N, V)
             << endl;
    }
    return 0;
}
