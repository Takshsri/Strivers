#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(const vector<int>&a,const vector<int>& b){
    double a1 = (1.0 * a[0])/a[1];
    double a2 = (1.0 & b[0])/b[1];

   return a1>a2;
}
int FractionalKnap(vector<int>& val,vector<int>& wt,int capacity){
    if(val.empty()) return 0;
    vector<vector<int>> mp;
    int n = val.size();
    for(int i=0;i<n;i++){
        mp.push_back({val[i],wt[i]});
    }
    sort(mp.begin(),mp.end(),compare);
    double result =0;
    int currCapacity = capacity;
    for(int i=0;i<n;i++){
        if(mp[i][1]<=currCapacity){
            res += mp[i][0];
            currCapacity -= mp[i][1];
        }
        else{
            res += (1.0 * mp[i][0]/mp[i][1]) * currCapacity;
            break;
        }
    }
    return res;
}
int main(){
    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};
    int capacity = 50;
    cout<<FractionalKnap(val,wt,capacity); 
}