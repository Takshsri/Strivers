#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int Triplets(vector<int>& a){
    int n = a.size();
    int count =0;
    for(int i=0;i<n;i++){
        int x=0;
        for(int k=i;k<n;k++){
            x ^= a[k];
            if(x==0){
                count += (k-i);
            }
        }
    }
    return count;
}
int Optimal(vector<int>& a){
    int n = a.size();
    int prefixXor=0;
    int total = 0;
    unordered_map<int,pair<int,int>> mp;
    mp[0] = {1,-1};
    for(int i=0;i<n;i++){
        prefixXor ^= a[i];
        if(mp.find(prefixXor)!=mp.end()){
            int count = mp[prefixXor].first;
            int index_sum = mp[prefixXor].second;
            total += (count*i)-index_sum - count;
        }
        mp[prefixXor].first+=1;
        mp[prefixXor].second+=i;  
    }
    return total;
}
int main(){
    vector<int> arr = {1, 1, 1, 1, 1};
    cout<<Triplets(arr);
}