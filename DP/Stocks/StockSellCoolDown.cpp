#include <iostream>
#include <vector>
using namespace std;

// 1. Recursion
int Recursion(vector<int>& a, int idx, int buy) {
    if (idx >= a.size())
        return 0;

    if (buy) {
        return max(
            -a[idx] + Recursion(a, idx + 1, 0),
            Recursion(a, idx + 1, 1)
        );
    }

    // After selling, skip the next day (cooldown)
    return max(
        a[idx] + Recursion(a, idx + 2, 1),
        Recursion(a, idx + 1, 0)
    );
}


// 2. Memoization
int RecM(vector<int>& a, int idx, int buy,
         vector<vector<int>>& dp) {

    if (idx >= a.size())
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    if (buy) {
        return dp[idx][buy] = max(
            -a[idx] + RecM(a, idx + 1, 0, dp),
            RecM(a, idx + 1, 1, dp)
        );
    }

    return dp[idx][buy] = max(
        a[idx] + RecM(a, idx + 2, 1, dp),
        RecM(a, idx + 1, 0, dp)
    );
}


// 3. Tabulation
int Tabulation(vector<int>& a) {
    int n = a.size();

    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--) {

        // Can buy
        dp[idx][1] = max(
            -a[idx] + dp[idx + 1][0],
            dp[idx + 1][1]
        );

        // Holding stock -> sell or skip
        dp[idx][0] = max(
            a[idx] + dp[idx + 2][1],
            dp[idx + 1][0]
        );
    }

    return dp[0][1];
}


int main() {

    vector<int> a = {4,9,0,4,10};

    cout << "Recursion: "
         << Recursion(a, 0, 1) << endl;

    vector<vector<int>> dp(
        a.size(),
        vector<int>(2, -1)
    );

    cout << "Memoization: "
         << RecM(a, 0, 1, dp) << endl;

    cout << "Tabulation: "
         << Tabulation(a) << endl;

    return 0;
}