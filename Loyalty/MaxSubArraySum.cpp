//Kadanes Algo

#include<iostream>
#include<vector>
using namespace std;
int MaxSum(vector<int>& a){
    int maxSum = INT_MIN;
    
    int currSum =a[0];
    int st =0,end =0,ans=-1;
    for(int i=1;i<a.size();i++){
        if(currSum <0){
            currSum = a[i];

            st = i;
        }
        else{
        currSum+= a[i];
        }
        if(currSum > maxSum){
            maxSum = currSum;
            ans = st;
            end = i;
        }
    }
    for(int i=ans;i<=end;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return maxSum;

}
int main(){
    vector<int> a = {7,9,-2,-3};
    cout<<MaxSum(a);
}