#include <iostream>
#include <vector>
using namespace std;

long Recursion(vector<int>& a, int n, int idx, int buy) {
    if (idx == n)
        return 0;

    long profit = 0;

    if (buy) {
        // Buy or skip
        profit = max(
            -a[idx] + Recursion(a, n, idx + 1, 0),
            Recursion(a, n, idx + 1, 1)
        );
    }
    else {
        // Sell or skip
        profit = max(
            a[idx] + Recursion(a, n, idx + 1, 1),
            Recursion(a, n, idx + 1, 0)
        );
    }

    return profit;
}

long RecM(vector<int>& a, int n, int idx, int buy,
          vector<vector<long>>& dp) {

    if (idx == n)
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    long profit;

    if (buy) {
        // Buy OR skip
        profit = max(
            -a[idx] + RecM(a, n, idx + 1, 0, dp),
            RecM(a, n, idx + 1, 1, dp)
        );
    }
    else {
        // Sell OR skip
        profit = max(
            a[idx] + RecM(a, n, idx + 1, 1, dp),
            RecM(a, n, idx + 1, 0, dp)
        );
    }

    return dp[idx][buy] = profit;
}
long Tabulation(vector<int>& a, int n) {

    vector<vector<long>> dp(n + 1, vector<long>(2, 0));

    // dp[n][0] = 0
    // dp[n][1] = 0

    for (int idx = n - 1; idx >= 0; idx--) {

        // buy = 1
        dp[idx][1] = max(
            -a[idx] + dp[idx + 1][0],
            dp[idx + 1][1]
        );

        // buy = 0
        dp[idx][0] = max(
            a[idx] + dp[idx + 1][1],
            dp[idx + 1][0]
        );
    }

    return dp[0][1];
}

int main() {
    vector<int> a = {7, 1, 5, 3, 6, 4};

    cout << Recursion(a, a.size(), 0, 1) << endl;
    int n = a.size();

    vector<vector<long>> dp(n, vector<long>(2, -1));

    cout << RecM(a, n, 0, 1, dp) << endl;
}