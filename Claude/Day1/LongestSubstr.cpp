#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int Longest(string s){
    unordered_set<char> mp;
    int maxi = 0;
    int left =0;
    for(int i=0;i<s.size();i++){
        while(mp.find(s[i])!=mp.end()){

            mp.erase(s[left++]);
        }
        mp.insert(s[i]);
        maxi = max(maxi,i-left+1);
    }
    return maxi;
}
int main(){
    string str = "abcabcbb";
    cout<<Longest(str);
}