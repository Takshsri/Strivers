#include<iostream>
#include<vector>
#include<string>
using namespace std;
int Decode(string s,int i){
    if(i==s.size()) return 1;
    if(s[i]=='0') return 0;
    int one = Decode(s,i+1);
    int two =0;
    if(i+1<s.size()){
        int num = (s[i]-'0')*10 +(s[i+1]-'0');
        if(num>=10 && num<=26){
            two = Decode(s,i+2);
        }
    }
    return one+two;
}
int DecodeM(string s,int i,vector<int>& dp){
    if(i==s.size()) return 1;
    if(s[i]=='0') return 0;
    if(dp[i]!=-1) return dp[i];
    int one = DecodeM(s,i+1,dp);
    int two =0;
    if(i+1<s.size()){
        int num = (s[i]-'0')* 10 +(s[i+1]-'0');
        if(num>=10 && num<=26){
            two = DecodeM(s,i+2,dp);
        }
    }
    return dp[i] = one+two;
}
int DecodeT(string s) {
    int n = s.size();

    vector<int> dp(n + 1, 0);

    dp[n] = 1;

    for(int i = n - 1; i >= 0; i--) {

        if(s[i] == '0')
            continue;

        // Take one digit
        dp[i] = dp[i + 1];

        // Take two digits
        if(i + 1 < n) {

            int num = (s[i] - '0') * 10
                    + (s[i + 1] - '0');

            if(num >= 10 && num <= 26) {
                dp[i] += dp[i + 2];
            }
        }
    }

    return dp[0];
}
int main(){
    string s = "223";
    vector<int> dp(s.size()+1,-1);
    cout<<Decode(s,0)<<endl;
    cout<<DecodeM(s,0,dp)<<endl;
    cout<<DecodeT(s)<<endl;
}