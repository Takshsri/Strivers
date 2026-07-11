#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<char>>& grid,int i,int j){
    int rows = grid.size();
    int cols = grid[0].size();
    if(i<0 || j<0 || i>=rows || j>=cols|| grid[i][j]=='0') return;
    grid[i][j] = '0';

    //recursion
    dfs(grid,i+1,j);//down
    dfs(grid,i-1,j);//up
    dfs(grid,i,j-1);//left
    dfs(grid,i,j+1);//right
}
int numIslands(vector<vector<char>>& grid){
    if(grid.empty()) return 0;
    int count =0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){
                count++; 
                dfs(grid,i,j);
            }
        }
    }
    return count;
}
int main()
{
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands = " << numIslands(grid);

    return 0;
}