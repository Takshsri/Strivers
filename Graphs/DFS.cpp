#include<iostream>
#include<vector>
using namespace std;
void dfsReg(vector<vector<int>>& a,vector<bool>& visited,int st,vector<int>& res){
    visited[st] = true;
    res.push_back(st);
    for(int i : a[st]){
        if(!visited[i]){
            dfsReg(a,visited,i,res);
        }
    }
}
vector<int> dfs(vector<vector<int>>& g){
    vector<bool> visited(g.size(),false);
    vector<int> res;
    dfsReg(g,visited,0,res);
    return res;
}
int main(){
    vector<vector<int>> g = {
        {1,2},
        {0,3},
        {0},
        {1}
    };
    vector<int> res = dfs(g);
    for(int i : res){
        cout<<i<<" ";
    }
}