#include<iostream>
#include<vector>
using namespace std;
//Recursion Fibonnaci
int Fib(int n){
    if(n<=1) return n;
    return Fib(n-1)+Fib(n-2);
}
//DP Memoization
int Fib(int n,vector<int> &dp){
    if(n<=1) return n;
    return dp[n] = Fib(n-1,dp) + Fib(n-2,dp);
}
//DP Tabulation
int FibT(int n,vector<int> &dp){
    
    dp[0] = 0,dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//DP Tabulation Optimal Space
int FibS(int n){
    int prev1 = 0,prev=1;
    for(int i=2;i<=n;i++){
        int curr = prev+prev1;
        prev1= prev;
        prev = curr;
    }
    return prev;
}
int main(){
    int n ;
    cin>>n; 
    vector<int> dp(n+1,-1);
    cout<<FibT(n,dp);
    cout<<endl<<FibS(n);
}