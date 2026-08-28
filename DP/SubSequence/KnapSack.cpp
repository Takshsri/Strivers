#include<iostream>
#include<vector>
using namespace std;

int Knapsack(vector<int>&wt,vector<int>& val,int capacity,int idx){
    if(idx ==0){
        if(wt[0]<=capacity){
            return val[0];
        }
        return 0;
    }

    int notTake = Knapsack(wt,val,capacity,idx-1);
    int take = 0;
    if(wt[idx]<=capacity){
        take = val[idx]+Knapsack(wt,val,capacity-wt[idx],idx-1);
    }
    return max(take,notTake);
}

int KnapsackM(vector<int>&wt,vector<int>& val,int capacity,int idx,vector<vector<int>>& dp){
    if(idx ==0){
        if(wt[0]<=capacity){
            return val[0];
        }
        return 0;
    }
    if(dp[idx][capacity]!=-1)return dp[idx][capacity];
    int notTake = KnapsackM(wt,val,capacity,idx-1,dp);
    int take = 0;
    if(wt[idx]<=capacity){
        take = val[idx]+KnapsackM(wt,val,capacity-wt[idx],idx-1,dp);
    }
    return dp[idx][capacity]=max(take,notTake);
}

int Tabulation(vector<int>& wt,vector<int>& val,int capacity){
    int n = wt.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    for(int c=wt[0];c<=capacity;c++){
        dp[0][c] = val[0];
    }
    for(int i=1;i<n;i++){
        for(int c=0;c<=capacity;c++){
            int notTake = dp[i-1][c];
            int take =0;
            if(wt[i]<=c){
                take = val[i]+dp[i-1][c-wt[i]];
            }
            dp[i][c] = max(take,notTake);
        }
    }
    return dp[n-1][capacity];
}

int main(){
    vector<int> wt = {1,3,4,5};
    vector<int> val = {1,4,5,7};
    int capacity =7;
    vector<vector<int>> dp(wt.size(),vector<int> (capacity+1,-1));
    cout<<KnapsackM(wt,val,capacity,3,dp);//3 is size-1 of array size;

    cout<<endl<<Knapsack(wt,val,capacity,3);
    cout<<endl<<Tabulation(wt,val,capacity);
}