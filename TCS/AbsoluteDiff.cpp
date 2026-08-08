#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> Diff(vector<int>& a,int k){
    unordered_map<int,int> mp;
    for(int i=0;i<a.size();i++){
        int first = a[i];
        int target1 = a[i] - k;
        int target2 = a[i] + k;
        if(mp.find(target1)!=mp.end()){
            return {i,mp[target1]};
        }
        if(mp.find(target2)  !=mp.end()){
            return {i,mp[target2]};
        }
        mp[a[i]] = i;
    }
    return {-1,-1};
}
int main(){
    vector<int> a = {1,8,3};
    vector<int> res = Diff(a,5); 
    for(int i : res){
        cout<<i<<" ";
    }
}