//Product of Array Except Self

#include<iostream>
#include<vector>
using namespace std;
//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

//You must write an algorithm that runs in O(n) time and without using the division operation.
int main(){
    vector<int> a = {-1,1,0,-3,3};
    long long prod = 1;
    for(int i : a){
        if(i==0){
            i = 1;
        }
        prod *= i;
    }
    cout<<prod<<endl;
    vector<int> res ;
    for(int i : a){
        cout<<i<<" ";
        cout<<prod/i<<endl;
        //re s.push_back(prod/i);
        
    }
    // for(int i : res){
    //     cout<<i<<" ";
    // }
}