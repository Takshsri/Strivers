#include<iostream>
#include<vector>
using namespace std;

//1. Maximum Sum Subarray of Size K

// Pattern: Basic Sliding Window

// Problem
// Given an array and integer k, find the maximum sum of any contiguous subarray of size k.
int Sum(vector<int>& a,int k){
    
    int maxSum =0;
    int currSum = 0;
    int n = a.size();
    for(int i=0;i<k;i++){
        currSum += a[i];
    }
    maxSum = currSum;
    int stIdx = 0;
    for(int i=k;i<n;i++){
        currSum += a[i]-a[i-k];
        if(currSum > maxSum){
            maxSum = currSum;
            stIdx = i-k+1;
        }
    }
    cout<<"SubArrays are:"<<endl;
    for(int i=stIdx;i<stIdx+k;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return maxSum;
}
int MaxSum(vector<int>& a,int k){
    int maxSum =0;
    int currSum = 0;
    int st=0;
    for(int i=0;i<k;i++){
        currSum += a[i];
    }
    maxSum = currSum;
    for(int i=k;i<a.size();i++){
        currSum += a[i]-a[i-k];
        if(currSum>maxSum){
            maxSum = currSum;
            st = i-k+1;

        }
    }
    for(int i=st;i<st+k;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return maxSum;
}
int main(){
    vector<int> a = {2,1,5,1,3,2};
    cout<<Sum(a,3);

}