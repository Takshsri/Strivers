#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Possible(string &s1, string &s2) {

    // s1 must have exactly one extra character
    if (s1.size() != s2.size() + 1)
        return false;

    int first = 0;
    int second = 0;

    while (first < s1.size() && second < s2.size()) {

        if (s1[first] == s2[second]) {
            first++;
            second++;
        }
        else {
            // Skip one character from s1
            first++;
        }
    }

    // All characters of s2 must be matched
    return second == s2.size();
}

int Longest(vector<string> &s) {

    int n = s.size();

    // Sort by length first
    sort(s.begin(), s.end(), [](string &a, string &b) {
        return a.size() < b.size();
    });

    vector<int> dp(n, 1);

    int maxi = 1;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (Possible(s[i], s[j]) &&
                dp[i] < dp[j] + 1) {

                dp[i] = dp[j] + 1;
            }
        }

        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

int main() {

    vector<string> s = {
        "a", "b", "ba", "bca", "bdc", "bdca"
    };

    cout << Longest(s);

    return 0;
}