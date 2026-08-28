#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int CountPartition(vector<int>& a,int d){
    int n = a.size();
    int sum = accumulate(a.begin(),a.end(),0);
    if(sum<d || (sum+d)%2!=0) return 0;
    int k = (sum+d)/2;

    vector<vector<int>> dp(n,vector<int>(k+1,0));
    if(a[0]==0){
        dp[0][0] = 2;//1 for Take and 1 for notTake so total 2 If array first element is 1
    }
    else{
        dp[0][0] = 1;
        if(a[0]<=k){
            dp[0][a[0]]=1;
        }
    }
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            int notTake = dp[i-1][target];
            int take = 0;
            if(a[i]<=target){
                take = dp[i-1][target-a[i]];
            }
            dp[i][target] = take+notTake;
        }
    }
    return dp[n-1][k];
}

int main(){
    vector<int> a = {1,1,2,3};
    cout<<CountPartition(a,1);
    // target = (sum + D) / 2
    //    = (7 + 1) / 2
    //    = 4
}