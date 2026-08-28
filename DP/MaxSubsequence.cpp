#include<iostream>
#include<vector>
using namespace std;
//recursion
int maxSubsequence(vector<int>& a,int idx){
    if(idx == 0) return a[idx];
    if(idx<0) return 0;
    int pick = a[idx]+maxSubsequence(a,idx-2);
    int notPick = 0+maxSubsequence(a,idx-1);
    return max(pick,notPick);
}
//memoization

int maxSequenceM(vector<int>& a, int idx, vector<int>& dp) {
    if(idx == 0) return a[idx];
    if(idx < 0) return 0;

    if(dp[idx] != -1)
        return dp[idx];

    int pick = a[idx] + maxSequenceM(a, idx-2, dp);
    int notPick = maxSequenceM(a, idx-1, dp);

    return dp[idx] = max(pick, notPick);
}
//tabulation
int maxSequenceT(vector<int>&a,int idx){
   int n = a.size();
   int prev = a[0]; 
   int prev1 = 0;
   for(int i=1;i<n;i++){
    int take = a[i];
    if(i>1) take += prev1;
    int notTake = 0+prev;
    int curr = max(take,notTake);
    prev1 = prev;
    prev = curr;
   }
   return prev;

}
int main(){ 
    vector<int> a = {2,4,8,9};
    vector<int> dp(a.size(),-1);
    cout<<maxSequenceT(a,3);
}  