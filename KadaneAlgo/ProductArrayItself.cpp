//Product of Array Except Self

#include<iostream>
#include<vector>
using namespace std;
void  Product(vector<int>& a){
    vector<int> suff(a.size(),1);
    vector<int> prefix(a.size(),1);
    int n = a.size();
    
    for(int i=1;i<a.size();i++){
        suff[i] = suff[i-1]*a[i-1];
    }
    
    for(int i=n-2;i>=0;i--){
        prefix[i] = prefix[i+1]*a[i+1];
    }

    for(int i=0;i<a.size();i++){
        cout<<prefix[i]*suff[i]<<" ";
    }
}

void ProductOptimal(vector<int>& a){
    int n = a.size();
    vector<int> ans(n,1);
    int prefix = 1;
    for(int i=0;i<n;i++){
        ans[i] = prefix;
        prefix *= a[i];
    }
    int suffix = 1;
    for(int i=n-1;i>=0;i--){
        ans[i] *= suffix;
        suffix *= a[i];
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

//You must write an algorithm that runs in O(n) time and without using the division operation.
int main(){
    vector<int> a = {1,2,3,4};
    ProductOptimal(a);
    // long long prod = 1;
    // for(int i : a){
    //     if(i==0){  
    //         i = 1;
    //     }
    //     prod *= i;
    // }
    // cout<<prod<<endl;
    // vector<int> res ;
    // for(int i : a){
    //     cout<<i<<" ";
    //     cout<<prod/i<<endl;
    //     //re s.push_back(prod/i);
        
    // }
    // // for(int i : res){
    // //     cout<<i<<" ";
    // // }
}