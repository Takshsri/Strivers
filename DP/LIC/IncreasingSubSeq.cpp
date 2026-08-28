#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int LIC(vector<int>& a, int idx, int prev) {
    if (idx == a.size()) return 0;

    int notTake = LIC(a, idx + 1, prev);

    int take = INT_MIN;

    if (prev == -1 || a[idx] > a[prev]) {
        take = 1 + LIC(a, idx + 1, idx);
    }

    return max(take, notTake);
}

int LICR(vector<int>& a, int idx, int prev, vector<vector<int>>& dp) {
    if (idx == a.size()) return 0;

    // Shift prev by 1
    if (dp[idx][prev + 1] != -1)
        return dp[idx][prev + 1];

    int notTake = LICR(a, idx + 1, prev, dp);

    int take = INT_MIN;

    if (prev == -1 || a[idx] > a[prev]) {
        take = 1 + LICR(a, idx + 1, idx, dp);
    }

    return dp[idx][prev + 1] = max(take, notTake);
}

int Tabulation(vector<int>& a){
    int n = a.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int idx=n-1;idx>=0;idx--){
        for(int prev=idx-1;prev>=-1;prev--){
            int notTake = dp[idx+1][prev+1];
            int take = 0;
            if(prev == -1 || a[idx]>a[prev]){
                take = 1+dp[idx+1][idx+1];
            }
            dp[idx][prev+1] = max(take,notTake);
        }
    }
    return dp[0][0];
}
void Print(vector<int>& a){
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Tabulation
    for (int idx = n - 1; idx >= 0; idx--) {
        for (int prev = idx - 1; prev >= -1; prev--) {

            int notTake = dp[idx + 1][prev + 1];

            int take = 0;

            if (prev == -1 || a[idx] > a[prev]) {
                take = 1 + dp[idx + 1][idx + 1];
            }

            dp[idx][prev + 1] = max(take, notTake);
        }
    }

    cout << "LIS length: " << dp[0][0] << endl;

    // Print LIS
    int idx = 0;
    int prev = -1;

    while (idx < n) {

        int notTake = dp[idx + 1][prev + 1];

        int take = -1;

        if (prev == -1 || a[idx] > a[prev]) { 
            take = 1 + dp[idx + 1][idx + 1];
        }

        if (take >= notTake) {
            cout << a[idx] << " ";
            prev = idx;
        }

        idx++;
    }
}
int main() {
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Recursion: " << LIC(a, 0, -1) << endl;

    int n = a.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    cout << "Memoization: " << LICR(a, 0, -1, dp) << endl;
    cout<<"Tabulation:"<<Tabulation(a)<<endl;
    Print(a);
}