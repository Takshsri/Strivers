#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int MajorityEle(vector<int>& a){
        int ans = 0;
        int freq = 0;
        for(int i=0;i<a.size();i++){
            if(freq ==0){
                ans = a[i];
            }
            else if(ans == a[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        int cnt1 = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]==ans){ 
                cnt1++;
        }

    }
    return (cnt1>a.size()/2)? ans : -1;
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
    vector<int> arr = {2,2,1,3,4,2,2 };
    cout<<"Majority Element :"<<MajorityEle(arr);
    
}