#include<iostream>
#include<vector>
using namespace std;
int prefixSum(vector<int>&a,int l,int r){
    vector<int> prefix(a.size());
    prefix[0] = a[0];
    for(int i=1;i<a.size();i++){
        prefix[i]= prefix[i-1]+a[i];
    }
    if(l==0)return prefix[r];
    else return prefix[r]-prefix[l-1];
}

int prefixSumPractice(vector<int>&a,int l,int r){
    vector<int> prefix(a.size());
    prefix[0]=a[0];
    for(int i=1;i<a.size();i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    if(l==0) return prefix[r];
    else return prefix[r]-prefix[l-1];
}
int main(){
    vector<int> a = {1,2,3,4,5};
    cout<<"PrefixSum of :"<<prefixSum(a,2,4);
}