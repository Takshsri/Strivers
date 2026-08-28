#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int Partition(vector<int>& a){
    int n = a.size();
    int sum = accumulate(a.begin(),a.end(),0);
    
    int target = sum/2;
    vector<vector<bool>> dp(n,vector<bool>(target+1,false));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    if(a[0]<=target){
        dp[0][a[0]] = true;
    }
    for(int i = 1; i < n; i++) {

        for(int k = 1; k <= target; k++) {

            bool notTake = dp[i-1][k];

            bool take = false;

            if(a[i] <= k) {
                take = dp[i-1][k-a[i]];
            }

            dp[i][k] = take || notTake;
        }
    }
    for(int k = target; k >= 0; k--) {

        if(dp[n-1][k]) {
            return abs(sum - 2 * k);
        }
    }
    return 0;
}
int main(){
    vector<int> a= {1,5,7,3};
    cout<<Partition(a);
}