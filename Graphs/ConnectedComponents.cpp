#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>>& a,vector<bool>& visited,int st){
    visited[st] = true;
    
    for(int i : a[st]){
        if(!visited[i]){
            dfs(a,visited,i);
        }
    }
}

int ConnectedComponent(vector<vector<int>>& g){
    int n = g.size();
    vector<bool> visited(n,false);
    int count =0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(g,visited,i);
            count++;
        }
    }
    return count;
}
int main(){
     vector<vector<int>> g = {
        {1},
        {0},
        {3},
        {2,4},
        {3},
        {}
    };

    cout << ConnectedComponent(g);
}