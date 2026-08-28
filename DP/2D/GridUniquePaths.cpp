#include <iostream>
#include <vector>
using namespace std;

int f(int i, int j) {

    // Starting cell
    if (i == 0 && j == 0)
        return 1;

    // Outside the grid
    if (i < 0 || j < 0)
        return 0;

    int up = f(i - 1, j);
    int left = f(i, j - 1);

    return up + left;
}
int fM(int i,int j,vector<vector<int>>& dp){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0 ) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = fM(i-1,j,dp);
    int left = fM(i,j-1,dp);
    return dp[i][j] = up+left;
} 
int UniquePaths(int m, int n) {
   // return f(m - 1, n - 1);
    vector<vector<int>> dp(m, vector< int>(n, -1));

   return fM(m-1,n-1,dp);
}
//Tabulation

int Tabulation(int m,int n){
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = 1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) continue;
            int up=0;
            int left = 0;
            if(i>0) up = dp[i-1][j];
            if(j>0) left = dp[i][j-1];
            dp[i][j] = up+left;
        
        }
    }
    return dp[m-1][n-1];
}
int main(){
    cout<<UniquePaths(3,3);
    cout<<endl<<Tabulation(3,3);
}