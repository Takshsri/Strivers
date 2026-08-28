#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int Valid(vector<int>& a,int k){
    int count =0; 
    int curr_xor = 0;
    unordered_map<int,int> mp;
    mp[0]=1;
     
    for(int i=0;i<a.size();i++){
       curr_xor ^=a[i];
       int target = curr_xor ^ k;
       if(mp.find(target)!=mp.end()){
        count+= mp[target];
       }
       mp[curr_xor]++;

    }
    return count;
}
int main(){
    vector<int> arr = {4,2,2,6,4};
    int k = 6;
    cout<<Valid(arr,k);
}