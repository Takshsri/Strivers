#include<iostream>
#include<vector>
using namespace std;
vector<int> AvgSubArr(vector<int>& a,int k){
    int n= a.size();
    if(k>n) return {};
    vector<int> res;
    int sum =0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    res.push_back(sum/k);
    for(int i=k;i<n;i++){
        sum += a[i]-a[i-k];
        res.push_back(sum/k);
    }
    return res;

}
int main(){
    vector<int> arr = {1,2,3,4,5};
    vector<int> res = AvgSubArr(arr,3);
    for(int i: res){
        cout<<i<<" ";
    }

}