#include<iostream>
#include<vector>
using namespace std;
int FrogJump(int i,vector<int>&a,int k){
    if(i==0) return 0;
    int minSteps = INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j>=0){
            int jump = FrogJump(i-j,a,k)+abs(a[i]-a[i-j]);
            minSteps = min(minSteps,jump);
        }
    }
    return minSteps;
}
//Memoization
int FrogJumpM(int idx, vector<int>& a, int k, vector<int>& dp) {
    if (idx == 0)
        return 0;

    // Already calculated
    if (dp[idx] != -1)
        return dp[idx];
    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (idx - j >= 0) {
            int jump = FrogJumpM(idx - j, a, k, dp)
                       + abs(a[idx] - a[idx - j]);
            minSteps = min(minSteps, jump);
        }
    }
        return dp[idx] = minSteps;
}
//Tabulation
int FrogJump(vector<int>& a, int k) {
    int n = a.size();

    vector<int> dp(n, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {

        int minSteps = INT_MAX;

        for (int j = 1; j <= k; j++) {

            if (i - j >= 0) {

                int jump = dp[i - j] + abs(a[i] - a[i - j]);

                minSteps = min(minSteps, jump);
            }
        }

        dp[i] = minSteps;
    }
    return dp[n-1];
}

int main(){
    vector<int> a = {10,20,30,10};
    int n = a.size();
    vector<int> dp(n,-1);
    cout<<FrogJump(a,2);

}