#include<iostream>
#include<vector>
#include<map>

using namespace std;
int SubArrays(vector<int>& a,int target){
    map<int,int> map;
    int prefixSum = 0;
    int count = 0;
    map[0] = 1;
    for(int i=0;i<a.size();i++){
        prefixSum+=a[i];
        if(map.find(prefixSum-target)!=map.end()){
            count += map[prefixSum-target];
        }
        map[prefixSum]++;
        
    }
    return count;
}

int count(vector<int>& a,int tar){
    map<int,int> mp;
    int count =0;
    int prefixSum = 0;
    mp[0]=1;
    for(int i=0;i<a.size();i++){
        prefixSum+=a[i];
        if(mp.find(prefixSum-tar)!=mp.end()){
            count += mp[prefixSum-tar];
        }
        mp[prefixSum]++;
    }
    return count;
}
int main(){
    vector<int> a = {1,2,3,4,5};
    cout<<"No of SubArrays:"<<count(a,5);
}