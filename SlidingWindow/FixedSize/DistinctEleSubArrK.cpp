// Distinct Elements in Every Window of Size K

// Hint:
// HashMap


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> DistinctK(vector<int>& a,int k){
    vector<int> res;
    unordered_map<int,int> mp;
    for(int i=0;i<k;i++){
        mp[a[i]]++;
    }
    res.push_back(mp.size());
    for(int i=k;i<a.size();i++){
        mp[a[i]]++;
        int outgoing_ele = a[i-k];
        mp[outgoing_ele]--;
        if(mp[outgoing_ele]==0){
            mp.erase(outgoing_ele);
        }
        res.push_back(mp.size());
    }
    return res;
}
int main(){
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    vector<int> res = DistinctK(arr,4);
    for(int i : res){
        cout<<i<<" ";
    }
}