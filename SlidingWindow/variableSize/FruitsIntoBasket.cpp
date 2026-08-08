#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int Basket(vector<int>& a){
    int left =0,maxLen =0;
    unordered_map<int,int> mp;
    for(int i=0;i<a.size();i++){
        mp[a[i]]++;
        while(mp.size()>2){
            mp[a[left]]--;
        
        if(mp[a[left]]==0){
            mp.erase(a[left]);
            
        }
        left++;
    }
        maxLen = max(maxLen,i-left+1);
    }
    return maxLen;
}

int main(){
    vector<int> a = {1,2,3,2,2};//ans - 4 if we select 2,3,2,2, that are 2 diff breeds of fruits
    cout<<Basket(a);//here actually k  is 2
}