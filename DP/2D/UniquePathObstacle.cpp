#include<iostream>
#include<vector>

using namespace std;
int UniquePath(vector<vector<int>>& a, int i, int j) {

    // Outside grid
    if (i < 0 || j < 0)
        return 0;

    // Obstacle
    if (a[i][j] == -1)
        return 0;

    // Starting point
    if (i == 0 && j == 0)
        return 1;

    int up = UniquePath(a, i - 1, j);
    int left = UniquePath(a, i, j - 1);

    return up + left;
}
int UniquePathM(vector<vector<int>>& a, int i, int j,
                vector<vector<int>>& dp) {

    // Outside grid
    if (i < 0 || j < 0)
        return 0;

    // Obstacle
    if (a[i][j] == -1)
        return 0;

    // Starting point
    if (i == 0 && j == 0)
        return 1;

    // Already calculated
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = UniquePathM(a, i - 1, j, dp);
    int left = UniquePathM(a, i, j - 1, dp);

    return dp[i][j] = up + left;
}
int Tabulation(vector<vector<int>>& a) {

    int m = a.size();
    int n = a[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Starting cell is blocked
    if (a[0][0] == -1)
        return 0;

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            // Starting cell
            if (i == 0 && j == 0)
                continue;

            // Obstacle
            if (a[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

int main() {

    vector<vector<int>> a = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    int m = a.size();
    int n = a[0].size();

    cout << "Recursion: "
         << UniquePath(a, m - 1, n - 1) << endl;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << "Memoization: "
         << UniquePathM(a, m - 1, n - 1, dp) << endl;

    cout << "Tabulation: "
         << Tabulation(a) << endl;

    return 0;
}