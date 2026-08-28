#include<iostream>
#include<vector>
using namespace std;
bool Target(vector<int>& a, int k, int idx) {

    if (k == 0)
        return true;

    if (idx == 0)
        return a[0] == k;

    bool notTake = Target(a, k, idx - 1);

    bool take = false;

    if (a[idx] <= k)
        take = Target(a, k - a[idx], idx - 1);

    return take || notTake;
}
bool TargetM(vector<int>& a, int k, int idx, vector<vector<int>>& dp) {

    if (k == 0)
        return true;

    if (idx == 0)
        return a[0] == k;

    // Already calculated
    if (dp[idx][k] != -1)
        return dp[idx][k];

    // Don't take current element
    bool notTake = TargetM(a, k, idx - 1, dp);

    // Take current element
    bool take = false;

    if (a[idx] <= k) {
        take = TargetM(a, k - a[idx], idx - 1, dp);
    }

    return dp[idx][k] = take || notTake;
}

int Tabulation(vector<int>& a, int k) {
    int n = a.size();

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Target = 0 is always possible
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Using only first element
    if (a[0] <= k) {
        dp[0][a[0]] = true; 
    }

    for (int idx = 1; idx < n; idx++) {
        for (int target = 1; target <= k; target++) {

            bool notTake = dp[idx - 1][target];

            bool take = false;

            if (a[idx] <= target) {
                take = dp[idx - 1][target - a[idx]];
            }

            dp[idx][target] = take || notTake;
        }
    }

    return dp[n - 1][k];
}
int main(){
    vector<int> a= {1,2,3,4};
    int target = 4;
    cout<<Target(a,target,a.size()-1);
    cout<<endl<<Tabulation(a,target);
}