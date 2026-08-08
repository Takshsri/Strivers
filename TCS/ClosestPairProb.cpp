#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;
vector<int> Closest(vector<int>& a,vector<int>& b,int x){
    int n = a.size();
    int m = b.size();
    int left =0;
    int right = m-1;
    int rightEle = 0,leftEle = 0;
    int diff = INT_MAX;
    while(left<n && right >=0){
        if(abs(a[left]+b[right]-x)<diff){
            diff = abs(a[left]+b[right]-x);
            leftEle = left;
            rightEle = right;
        }
        else if(a[left]+b[right]<x){
            left++;
        }
        else{
            right--;
        }
    }
    return {a[leftEle],b[rightEle]};
}
vector<int> TwoSum(vector<int>& a,int x){
    int l = 0;
    int r = a.size()-1;
    while(l<r){
        if(a[l]+a[r] == x){
            return {l,r};   //1 4 5 7
        }
        else if(a[l]+a[r]<x){
            l++;
        }
        else {
            r--;
        }
    }
    return {-1,-1};
}
vector<int> Twosum(vector<int>& a,int x){
    unordered_map<int,int> mp;
    for(int i =0;i<a.size();i++){
        int first = a[i];
        int second = x-first;
        if(mp.find(second)!=mp.end()){
            return {i,mp[second]};
            break;
        }
        mp[first] = i;
    }
    return {-1,-1};
}
vector<int> diff(vector<int>& a,int k){
    unordered_map<int,int> mp;
    for(int i=0;i<a.size();i++){
        int first = a[i];
        int second = first-k;
        if(mp.find(second)!=mp.end()){
            return {i,mp[second]};
        }
        mp[first] = i;
    }
    return {-1};
}
int main(){
    vector<int> a = {1,4,5,7};
    vector<int> b = {10,20,30,40};
    int target = 39;
    vector<int> res = Closest(a,b,target);
    for(int i : res){
        cout<<i<<" ";
    }
    vector<int> prob = Twosum(b,50);
    for(int i : prob){
        cout<<i<<" ";
    }
}