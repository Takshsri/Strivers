#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> majorityElement(vector<int>& a){
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<a.size();i++){
        mp[a[i]]++;
    }
    for(auto it : mp){
        if(it.second > a.size()/3){
            ans.push_back(it.first);
        }
    }
    return ans;

}

//Boyer-Mooore Voting Algorithm
int main(){
    vector<int> arr = {1,2};
    vector<int> res = majorityElement(arr);
    for(int i : res){
        cout<<i<<" ";
    }
}