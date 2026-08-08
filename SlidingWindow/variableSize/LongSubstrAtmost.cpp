#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
int Longest(string a,int k){
    int left =0;
    unordered_map<int,int> mp;
    int maxi =0;
    for(int i=0;i<a.size();i++){
        mp[a[i]]++;
        while(mp.size()>k){
            mp[a[left]]--;
            if(mp[a[left]]==0){
                mp.erase(a[left]);
            }
            left++;
        }
        maxi = max(maxi,i-left+1);
    }
    return maxi;
}

int main(){
    string s= "acaba";//aca or aba length is 3
    int k = 2;
    cout<<Longest(s,k);
}