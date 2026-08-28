#include<iostream>
#include<vector>
using namespace std;
int Count(vector<int>& a,int k,int idx){
    if(k==0) return 1;
    if(idx ==0) return (a[idx]==k);
    int notTake = Count(a,k,idx-1);
    int take =0;
    if(a[idx]<=k){
        take = Count(a,k-a[idx],idx-1);
    }
    return take + notTake;
}
//memoization
int CountM(vector<int>& a,int k,int idx,vector<vector<int>>& dp){
    if(k==0) return 1;
    if(idx ==0) return (a[idx]==k);
    if(dp[idx][k]!=-1) return dp[idx][k];

    int notTake = CountM(a,k,idx-1,dp);
    int take =0;
    if(a[idx]<=k){
        take = CountM(a,k-a[idx],idx-1,dp);
    }
    return take + notTake;
}

int Tabulation(vector<int>& a,int k){
    int n = a.size();
    vector<vector<int>> dp(a.size(),vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    if(a[0]<=k){
        dp[0][a[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int target =1;target<=k;target++){
            int notTake = dp[i-1][target];
            int take = 0;
            if(a[i]<=target){
                take = dp[i-1][target-a[i]];
            }
            dp[i][target] = notTake+take;
        }
    }
    
    return dp[n-1][k];
}
int main(){
    vector<int> a = {1,2,3,3};
    int k = 6;
    vector<vector<int>> dp(a.size(),vector<int>(k+1,-1));
    cout<<CountM(a,k,a.size()-1,dp);
    cout<<endl<<Tabulation(a,k);
}