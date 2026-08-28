#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Bitonic(vector<int>& arr){
    int n = arr.size();
    vector<int> dp1(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp1[i]<dp1[j]+1){
                dp1[i] = dp1[j]+1;
            }
        }
    }
    vector<int> dp2(n,1);
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[i] && dp2[i]<dp2[j]+1){
                dp2[i] = dp2[j]+1;
            }
        }
    }
    int maxi =0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,dp1[i]+dp2[i]-1);
    }
    return maxi;
 
}
int main(){
    vector<int>  a= {1,11,2,10,4,5,2,1};
    cout<<Bitonic(a);
}