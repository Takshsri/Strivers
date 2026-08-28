#include <iostream>
#include <vector>
#include <string>
using namespace std;


// =====================================================
// 1. RECURSION
// =====================================================

bool Rec(string &s, string &p, int i, int j) {

    // Both strings exhausted
    if(i == 0 && j == 0)
        return true;

    // Pattern exhausted but string remains
    if(j == 0)
        return false;

    // String exhausted
    // Remaining pattern must contain only '*'
    if(i == 0) {
        for(int k = 0; k < j; k++) {
            if(p[k] != '*')
                return false;
        }
        return true;
    }

    // Character match or '?'
    if(p[j-1] == s[i-1] || p[j-1] == '?') {
        return Rec(s, p, i-1, j-1);
    }

    // '*'
    if(p[j-1] == '*') {

        // '*' matches zero characters
        // OR
        // '*' matches one/more characters
        return Rec(s, p, i, j-1) ||
               Rec(s, p, i-1, j);
    }

    // Characters don't match
    return false;
}


// =====================================================
// 2. MEMOIZATION
// =====================================================

bool RecM(string &s, string &p, int i, int j,
          vector<vector<int>> &dp) {

    if(i == 0 && j == 0)
        return true;

    if(j == 0)
        return false;

    if(i == 0) {
        for(int k = 0; k < j; k++) {
            if(p[k] != '*')
                return false;
        }
        return true;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    // Character match or '?'
    if(p[j-1] == s[i-1] || p[j-1] == '?') {

        return dp[i][j] =
            RecM(s, p, i-1, j-1, dp);
    }

    // '*'
    if(p[j-1] == '*') {

        return dp[i][j] =
            RecM(s, p, i, j-1, dp) ||
            RecM(s, p, i-1, j, dp);
    }

    return dp[i][j] = false;
}


// =====================================================
// 3. TABULATION
// =====================================================

bool Tabulation(string &s, string &p) {

    int n = s.size();
    int m = p.size();

    vector<vector<bool>> dp(
        n+1,
        vector<bool>(m+1, false)
    );

    // Both empty
    dp[0][0] = true;

    // Empty s
    // Pattern can match empty only if
    // all characters are '*'
    for(int j = 1; j <= m; j++) {

        if(p[j-1] == '*')
            dp[0][j] = dp[0][j-1];

        else
            dp[0][j] = false;
    }

    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= m; j++) {

            // Normal character or '?'
            if(p[j-1] == s[i-1] ||
               p[j-1] == '?') {

                dp[i][j] = dp[i-1][j-1];
            }

            // '*'
            else if(p[j-1] == '*') {

                dp[i][j] =
                    dp[i][j-1] ||
                    dp[i-1][j];
            }

            // No match
            else {

                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}


// =====================================================
// MAIN
// =====================================================

int main() {

    string s = "adceb";
    string p = "*a*b";

    int n = s.size();
    int m = p.size();

    // Recursion
    cout << "Recursion: "
         << Rec(s, p, n, m) << endl;

    // Memoization
    vector<vector<int>> dp(
        n+1,
        vector<int>(m+1, -1)
    );

    cout << "Memoization: "
         << RecM(s, p, n, m, dp) << endl;

    // Tabulation
    cout << "Tabulation: "
         << Tabulation(s, p) << endl;

    return 0;
}  