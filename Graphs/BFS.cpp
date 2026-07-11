#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> bfs(vector<vector<int>>& g){
    vector<bool> visited(g.size(),false);
    vector<int> res;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(int i : g[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return res;
}
int main(){
     vector<vector<int>> g = {
        {1,2},
        {0,3},
        {0},
        {1}
    };

    vector<int> ans = bfs(g);

    for (int x : ans)
        cout << x << " ";
}