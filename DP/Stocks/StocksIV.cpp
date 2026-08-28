#include <iostream>
#include <vector>
using namespace std;

// 1. Recursion
int Recursion(vector<int>& a, int idx, int buy, int cap) {
    if (idx == a.size() || cap == 0)
        return 0;

    if (buy) {
        return max(
            -a[idx] + Recursion(a, idx + 1, 0, cap),
            Recursion(a, idx + 1, 1, cap)
        );
    }

    return max(
        a[idx] + Recursion(a, idx + 1, 1, cap - 1),
        Recursion(a, idx + 1, 0, cap)
    );
}


// 2. Memoization
int RecM(vector<int>& a, int idx, int buy, int cap,
         vector<vector<vector<int>>>& dp) {

    if (idx == a.size() || cap == 0)
        return 0;

    if (dp[idx][buy][cap] != -1)
        return dp[idx][buy][cap];

    if (buy) {
        return dp[idx][buy][cap] = max(
            -a[idx] + RecM(a, idx + 1, 0, cap, dp),
            RecM(a, idx + 1, 1, cap, dp)
        );
    }

    return dp[idx][buy][cap] = max(
        a[idx] + RecM(a, idx + 1, 1, cap - 1, dp),
        RecM(a, idx + 1, 0, cap, dp)
    );
}


// 3. Tabulation
int Tabulation(vector<int>& a,int k) {
    int n = a.size();

    // dp[idx][buy][cap]
    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(2, vector<int>(k, 0))
    );

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {

                if (buy) {
                    dp[idx][buy][cap] = max(
                        -a[idx] + dp[idx + 1][0][cap],
                        dp[idx + 1][1][cap]
                    );
                }
                else {
                    dp[idx][buy][cap] = max(
                        a[idx] + dp[idx + 1][1][cap - 1],
                        dp[idx + 1][0][cap]
                    );
                }
            }
        }
    }

    return dp[0][1][k];
}


int main() {

    vector<int> a = {3, 3, 5, 0, 0, 3, 1, 4};
    int k = 2;
    // 1. Recursion
    cout << "Recursion: "
         << Recursion(a, 0, 1, k) << endl;


    // 2. Memoization
    int n = a.size();

    vector<vector<vector<int>>> dp(
        n,
        vector<vector<int>>(2, vector<int>(3, -1))
    );

    cout << "Memoization: "
         << RecM(a, 0, 1, k, dp) << endl;


    // 3. Tabulation
    cout << "Tabulation: "
         << Tabulation(a,k) << endl;

    return 0;
}