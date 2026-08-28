#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int Rec(string &s1,string &s2,int idx1,int idx2){
    if(idx1<0 || idx2<0) return 0;
    if(s1[idx1]==s2[idx2]) return 1+Rec(s1,s2,idx1-1,idx2-1);
    return max(Rec(s1,s2,idx1-1,idx2),Rec(s1,s2,idx1,idx2-1));
}
int RecM(string &s1,string &s2,int idx1,int idx2,vector<vector<int>> & dp){
    if(idx1<0 || idx2<0) return 0;
    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    if(s1[idx1]==s2[idx2]) return dp[idx1][idx2] =  1+RecM(s1,s2,idx1-1,idx2-1,dp);
    return dp[idx1][idx2] = max(RecM(s1,s2,idx1-1,idx2,dp),RecM(s1,s2,idx1,idx2-1,dp));
}

int Tabulation(string &s1,string &s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

string PrintLCS(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build LCS table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Backtrack to construct LCS
    int i = n;
    int j = m;

    string lcs = "";

    while(i > 0 && j > 0) {

        if(s1[i-1] == s2[j-1]) {
            lcs += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    } 

    // We constructed it backwards
    reverse(lcs.begin(), lcs.end());

    return lcs;
}
int main(){
    string s1 = "abdce";
    string s2 = "aedc";
    cout<<Rec(s1,s2,s1.size()-1,s2.size()-1);
     vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
     cout<<endl<<RecM(s1,s2,s1.size()-1,s2.size()-1,dp);
     cout<<endl<<Tabulation(s1,s2)<<endl;
     cout<<PrintLCS(s1,s2);
}