#include<iostream>
#include<vector>
using namespace std;
//recursion method
int FrogJump(int idx,vector<int>& a){
    if(idx ==0) return 0;
    int left = FrogJump(idx-1,a)+abs(a[idx]-a[idx-1]);
    int right = INT_MAX;
    if(idx>1){
        right = FrogJump(idx-2,a)+abs(a[idx]-a[idx-2]);
    } 

    return min(left,right);
}
//using DP
int FrogJumpD(int idx,vector<int>&a,vector<int>& dp){
    if(idx==0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int left = FrogJumpD(idx -1,a,dp)+abs(a[idx]-a[idx-1]);
    int right = INT_MAX;
    if(idx>1){
        right = FrogJumpD(idx-2,a,dp)+abs(a[idx]-a[idx-2]);
    }
    return dp[idx] = min(left,right);
}
//using Tabulation 
int FrogJumpT(int n,vector<int>& a){
    // vector<int> dp(n,-1);
    // dp[0] = 0;
    // for(int i=1;i<n;i++){
    //     int fs = dp[i-1]+abs(a[i]-a[i-1]);
    //     int rs = INT_MAX;
    //     if(i>1){
    //         rs = dp[i-2]+abs(a[i]-a[i-2]);
    //     }
    //     dp[i] = min(fs,rs);
    // }
    // return dp[n-1];

    //another method with space complexity O(1)
    vector<int> dp(n,-1);
    int prev = 0;
    int prev1 = 0;
    for(int i=1;i<n;i++){
        int fs = prev + abs(a[i]-a[i-1]);
        int rs = INT_MAX;
        if(i>1){
            rs = prev1 +abs(a[i]-a[i-2]);
        }
        int curr = min(rs,fs);
        prev1 = prev;
        prev = curr;
    }
    return prev;
}
int main(){
    vector<int> arr = {10,20,30,10};
    int n = arr.size();
    vector<int> dp(n+1,-1);
    cout<<FrogJumpD(n-1,arr,dp);
    cout<<endl<<FrogJumpT(n-1,arr);
}