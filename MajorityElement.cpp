#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int MajorityEle(vector<int>& a){
    int ans = 0;
    int freq =0;
    for(int i=0;i<a.size();i++){
        if(freq==0){
            ans = a[i];
        }
        if(ans == a[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}
//using hash
int MajorityEleHash(vector<int>& a){
    unordered_map<int,int> mp;
    for(int i=0;i<a.size();i++){
        mp[a[i]]++;
    }
    \
    for(auto it:mp){
        if(it.second > a.size()/2){
            return it.first;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {6,5,5};
    cout<<"Majority Element :"<<MajorityEleHash(arr);
}