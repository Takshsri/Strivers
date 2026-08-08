#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//The maximum length of a substring with identical characters after making 
//at most k replacements is 4 for the input string s = "AABABBA" and k = 1
int Replace(string s,int k){
    vector<int> res(26,0);
    int left =0;
    int maxLength =0;
    int maxFreq=0;
    for(int i=0;i<s.size();i++) {
        res[s[i]-'A']++;
        maxFreq = max(maxFreq,res[s[i]-'A']);


        if((i-left+1)-maxFreq>k){
            res[s[left]-'A']--;
            left++;
        }
        maxLength = max(maxLength,i-left+1);
    }
    return maxLength;
}
int main(){
    string s ="AABABBA";
    cout<<Replace(s,1);
}