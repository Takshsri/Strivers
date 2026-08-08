#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int NoSubarrays(vector<int>& a,int k){
    int count =0;
    int sum =0;
    unordered_map<int,int> mp;
    mp[0] = 1;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        if(mp.find(sum-k)!=mp.end()){
            count += mp[sum-k];
        }
        mp[sum]++;
    }
    return count;
}
int main(){
    vector<int> a = {1,1,1};
    cout<<NoSubarrays(a,2);
}