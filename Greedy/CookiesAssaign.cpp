#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int CookiesAssaign(vector<int>&g,vector<int>& s){
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int l =0;
    int r = 0;
    int m = g.size(),n = s.size();
    while(l<m && r<n){
        if(g[r]>=s[l]){
           r++;
        }
        l++;
    }
    return r;
}
int main(){ 
    vector<int> g = {1,2};
    vector<int> s = {1,2,3};
    cout<<CookiesAssaign(g,s);
}