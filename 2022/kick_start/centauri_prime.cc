#include <iostream>
#include <string>

using namespace std;

/*
3
Mollaristan
Auritania
Zizily

Case #1: Mollaristan is ruled by Bob.
Case #2: Auritania is ruled by Alice.
Case #3: Zizily is ruled by nobody.

*/


string GetRuler(const string &kingdom)
{
    // TODO: implement this method to determine the ruler name, given the
    // kingdom.
    string ruler = "Bob";
    int len = kingdom.length();
    char c = kingdom[len - 1];
    c = c | 0x20;  // to lower case
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        ruler = "Alice";
    } else if (c == 'y') {
        ruler = "nobody";
    }
    return ruler;
}

int main()
{
    int testcases;
    cin >> testcases;
    string kingdom;

    for (int t = 1; t <= testcases; ++t) {
        cin >> kingdom;
        cout << "Case #" << t << ": " << kingdom << " is ruled by "
             << GetRuler(kingdom) << ".\n";
    }
    return 0;
}
