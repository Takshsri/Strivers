#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
int Longest(string str){
    int left =0;
    int maxCount=0;
    unordered_set<char> mp;
    for(int i=0;i<str.size();i++){
        while(mp.find(str[i])!=mp.end()){
                mp.erase(str[left]);
                left++;
        }
        mp.insert(str[i]);
        maxCount = max(maxCount,i-left+1);
    }
    return maxCount;
}
int main(){
    string str = "thisisalongx";
    cout<<Longest(str);
}