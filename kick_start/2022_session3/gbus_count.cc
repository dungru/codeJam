//#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> numberOfGBusesPerCity(vector<int> cities,
                                  vector<pair<int, int> > gBuses)
{
    vector<int> numberOfGBuses(cities.size());

    vector<int> count_map(5000, 0);  // 1≤Bi≤5000, for all i.
    for (auto bus : gBuses) {
        int x = bus.first;
        int y = bus.second;
        for (int i = x; i <= y; i++) {
            count_map[i]++;
        }
    }

    for (int i = 0; i < cities.size(); i++) {
        numberOfGBuses[i] = count_map[cities[i]];
    }
    // TODO: Complete this function to return the number of GBuses serving each
    // of the specified cities.
    return numberOfGBuses;
}

int main()
{
    int T;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++) {
        int N;
        cin >> N;
        // Stores the range of cities served by every GBus.
        vector<pair<int, int> > gBuses(N);
        for (int i = 0; i < N; i++) {
            cin >> gBuses[i].first >> gBuses[i].second;
        }
        int P;
        cin >> P;
        vector<int> cities(P);
        for (int i = 0; i < P; i++) {
            cin >> cities[i];
        }
        cout << "Case #" << testCase << ": ";
        vector<int> numberOfGBuses = numberOfGBusesPerCity(cities, gBuses);
        for (int i = 0; i < numberOfGBuses.size(); i++) {
            cout << numberOfGBuses[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
