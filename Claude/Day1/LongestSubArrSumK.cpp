#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int Longest(vector<int>& a,int k){
    int maxLength =0,sum=0;
    unordered_map<int,int> mp;
    mp[0]=-1;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        if(mp.find(sum-k)!=mp.end()){
            maxLength = max(maxLength,i-mp[sum-k]);
        }

        if(mp.find(sum)==mp.end()){
            mp[sum] = i;
        }
    }
    return maxLength;
}
int MinPlatforms(vector<int>&a,vector<int>& b){
    int n = a.size();
    int m = b.size();
    int mini= 0;
    int i=0,j=0;
    int count =0;
    int maxCount = 0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while(i<n && j<m){
        if(a[i]<=b[j]){
            count++;
            i++;
        }
        else{
            count --;
            j++;
        }
        maxCount = max(maxCount,count);
    }
    return maxCount;
}
int main(){
    vector<int> a = {1,-1,5,-2,3};
    int k = 3;
    cout<<Longest(a,k);
    cout<<endl;
    vector<int> arr = {900,910,950,1100};
    vector<int> dep = {910,1000,990,1120};
    cout<<MinPlatforms(arr,dep)<<endl;
     
}