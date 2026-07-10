#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> Target(vector<int>&a,int k){
    unordered_map<int,int> m;
    
    for(int i=0;i<a.size();i++){
        int first = a[i];
        int sec = k-a[i];
        if(m.find(sec)!=m.end()){
            return {m[sec],i};
            
        }
        m[first] = i;
    }
    return {-1,-1};
}
int main(){
    vector<int> a = {0,-1,2,-3,1};
    vector<int> res = Target(a,-1);
    for(int i : res){
        cout<<i<<" ";
    }
}