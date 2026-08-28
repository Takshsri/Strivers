#include<iostream>
#include<vector>
using namespace std;

int Rec(vector<int>& a,int idx,int k){
    if(idx==0){
        if(k%a[idx]==0) return k/a[idx];
        else return 1e9;
    }
    int notTake = 0 +Rec(a,idx-1,k);
    int take = INT_MAX;
    if(a[idx]<=k){
        take = 1 + Rec(a,idx,k-a[idx]); //because of this this tends to be O(2^N) complexity
    }
    return min(take,notTake);
}
int RecM(vector<int>& a,int idx,int k,vector<vector<int>>& dp){
    if(idx==0){
        if(k%a[idx]==0) return k/a[idx];
        else return 1e9;
    }
    if(dp[idx][k]!=-1) return dp[idx][k];
    int notTake = 0 +RecM(a,idx-1,k,dp);
    int take = INT_MAX;
    if(a[idx]<=k){
        take = 1 + RecM(a,idx,k-a[idx],dp); //because of this this tends to be O(2^N) complexity
    }
    return min(take,notTake);
}
int Tabulation(vector<int>& a, int k){
    int n = a.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    // Base case
    for(int T = 0; T <= k; T++){
        if(T % a[0] == 0)
             dp[0][T] = T / a[0];
        else
            dp[0][T] = 1e9;
    }

    // Fill DP table
    for(int i = 1; i < n; i++){
        for(int t = 0; t <= k; t++){

            int notTake = dp[i-1][t];

            int take = 1e9;
            if(a[i] <= t){
                take = 1 + dp[i][t-a[i]];
            }

            dp[i][t] = min(take, notTake);
        }
    }

    return dp[n-1][k];
}

int main(){
    vector<int> a = {1,2,5};
    
    int k = 11;
    vector<vector<int>> dp (a.size(),vector<int>(k+1,-1));
     cout<<RecM(a,2,k,dp);
     cout<<endl<<Tabulation(a,k);
    
}