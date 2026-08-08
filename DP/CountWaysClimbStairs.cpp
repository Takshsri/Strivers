#include<iostream>
#include<vector>
using namespace std;
//recursion
int Climb(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    int left = Climb(n-1);
    int right = Climb(n-2);
    return left+right;
}
//recursion memoization
int ClimbM(int n,vector<int>&dp){
    if(n==0) return 1;
    if(n==1) return 1;
    int left = ClimbM(n-1,dp);
    int right = ClimbM(n-2,dp);
    return dp[n] = left+right;
}
    int climbStairs(int n) {
       int prev =1,prev1=1;
       for(int  i=2;i<=n;i++){
            int curr = prev+prev1;
            prev1 = prev;
            prev = curr;
       }
       return prev;

    } 

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<ClimbM(n,dp);

}