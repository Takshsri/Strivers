#include <iostream>
#include <vector>
using namespace std;

// 1. Recursion
int Recursion(vector<int>& a, int idx, int buy, int fee) {
    if (idx == a.size())
        return 0;

    if (buy) {
        return max(
            -a[idx] + Recursion(a, idx + 1, 0, fee),
            Recursion(a, idx + 1, 1, fee)
        );
    }

    return max(
        a[idx] - fee + Recursion(a, idx + 1, 1, fee),
        Recursion(a, idx + 1, 0, fee)
    );
}


// 2. Memoization
int RecM(vector<int>& a, int idx, int buy, int fee,
         vector<vector<int>>& dp) {

    if (idx == a.size())
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    if (buy) {
        return dp[idx][buy] = max(
            -a[idx] + RecM(a, idx + 1, 0, fee, dp),
            RecM(a, idx + 1, 1, fee, dp)
        );
    }

    return dp[idx][buy] = max(
        a[idx] - fee + RecM(a, idx + 1, 1, fee, dp),
        RecM(a, idx + 1, 0, fee, dp)
    );
}


// 3. Tabulation
int Tabulation(vector<int>& a, int fee) {
    int n = a.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--) {

        // Buy
        dp[idx][1] = max(
            -a[idx] + dp[idx + 1][0],
            dp[idx + 1][1]
        );

        // Sell
        dp[idx][0] = max(
            a[idx] - fee + dp[idx + 1][1],
            dp[idx + 1][0]
        );
    }

    return dp[0][1];
}


int main() {

    vector<int> a = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    // Recursion
    cout << "Recursion: "
         << Recursion(a, 0, 1, fee) << endl;

    // Memoization
    vector<vector<int>> dp(
        a.size(),
        vector<int>(2, -1)
    );

    cout << "Memoization: "
         << RecM(a, 0, 1, fee, dp) << endl;

    // Tabulation
    cout << "Tabulation: "
         << Tabulation(a, fee) << endl;

    return 0;
}