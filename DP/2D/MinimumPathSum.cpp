#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursion
int MinSum(int i, int j, vector<vector<int>>& a){

    if(i == 0 && j == 0)
        return a[i][j];

    if(i < 0 || j < 0)
        return INT_MAX;

    int up = MinSum(i-1, j, a);
    int left = MinSum(i, j-1, a);

    if(up != INT_MAX)
        up += a[i][j];

    if(left != INT_MAX)
        left += a[i][j];

    return min(up, left);
}

// Memoization
int MinSumM(int i, int j, vector<vector<int>>& a,
            vector<vector<int>>& dp){

    if(i == 0 && j == 0)
        return a[i][j];

    if(i < 0 || j < 0)
        return INT_MAX;

    if(dp[i][j] != -1)
        return dp[i][j];

    int up = MinSumM(i-1, j, a, dp);
    int left = MinSumM(i, j-1, a, dp);

    if(up != INT_MAX)
        up += a[i][j];

    if(left != INT_MAX)
        left += a[i][j];

    return dp[i][j] = min(up, left);
}
// Tabulation
int Tabulation(vector<vector<int>>& a){
 
    int n = a.size();
    int m = a[0].size();
 
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(i == 0 && j == 0){
                dp[i][j] = a[i][j];
            }
            else{

                int up = INT_MAX;
                int left = INT_MAX;

                if(i > 0)
                    up = a[i][j] + dp[i-1][j];

                if(j > 0)
                    left = a[i][j] + dp[i][j-1];

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[n-1][m-1];
}


int main(){

    vector<vector<int>> a = {
        {5, 7, 6},
        {11, 5, 2}
    };

    vector<vector<int>> dp(2, vector<int>(3, -1));

    cout << "Recursion: "
         << MinSum(1, 2, a) << endl;

    cout << "Memoization: "
         << MinSumM(1, 2, a, dp) << endl;

    cout << "Tabulation: "
         << Tabulation(a) << endl;

    return 0;
}