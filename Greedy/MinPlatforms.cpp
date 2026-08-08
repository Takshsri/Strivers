#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int MinRequired(vector<int> &arr,vector<int> &dep){
    int n = arr.size() ,m = dep.size();

    int i=0,j=0;
    int maxCount =0;
    
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int count =0;
    while(i<n && j<m){
        
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        maxCount = max(maxCount,count);

    }

    return maxCount;
     
}

vector<int> getRemovableIndices(string str1, string str2) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=0;i<str1.size();i++){
            mp[str1[i]]++;
        }
        for(int i=0;i<str2.size();i++){
            mp[str2[i]]--;
        }
        char val;
        for(auto it : mp){
            if(it.second!=0){
                val+=it.first;
                
            }
        }
            for(int i=0;i<str1.size();i++){
                if(str1[i]==val){
                    res.push_back(i);
                
            }
            
        }
        
        return res;
}

int main(){
    vector<int> arr = {900,945,955,1100,1500,1800};
    vector<int> dep = {920,1200,1130,1150,1900,2000};
    cout<<MinRequired(arr,dep);

    string s1 = "aabbb";
    string s2 = "aabb";
    vector<int> ans = getRemovableIndices(s1,s2);
    cout<<endl;
    for(int i : ans){
        cout<<i<<" ";
    }
}