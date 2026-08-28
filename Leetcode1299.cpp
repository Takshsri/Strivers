//Replace 1299. Replace Elements with Greatest Element on Right Side

// Given an array arr, 
//replace every element in that array with the greatest element among the elements to its right, 
//and replace the last element with -1.

// After doing so, return the array.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> Greater(vector<int>& a){
    int n = a.size();
    int maxRight =  -1;
    for(int i=n-1;i>=0;i--){
        int current = a[i];
        a[i] = maxRight;
        maxRight = max(maxRight,current);

    }
    return a ;
}

int main(){
    vector<int> a = {17,18,5,4,6,1};
    vector<int> res = Greater(a);   
    for(int i : res){
        cout<<i<<" ";
    }
}