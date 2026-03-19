#include<iostream>
#include<vector>
using namespace std;
int Sum(vector<int>& a,int k){
    int sum =0;
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
int main(){
    vector<int> a = {4,5,-3,0,1};
    cout<<Sum(a,3);
}