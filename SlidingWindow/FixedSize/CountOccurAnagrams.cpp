#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
int CountAnagrams(string txt,string pat){
    unordered_map<char,int>mp;
    for(char ch : pat){
        mp[ch]++;
    }
    int count = mp.size();
    int k = pat.size();
    int i=0,j=0,ans=0;
    while(j<txt.size()){
        if(mp.find(txt[j])!=mp.end()){
            mp[txt[j]]--;
            if(mp[txt[j]]==0)
                count--;
        }
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(count ==0){ 
                ans++;
            }
            if(mp.find(txt[i])!=mp.end()){
                if(mp[txt[i]]==0){
                    count++;
                }
                mp[txt[i]]++;
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main(){
    string txt = "aabaabaa";
    string pat = "aaba";
    //output = 4
    cout<<CountAnagrams(txt,pat);
}