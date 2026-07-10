#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int RangeSum(vector<int>& a,int l,int r){
    vector<int> prefix(a.size());
    prefix[0] = a[0];
    for(int i=1;i<a.size();i++){
        prefix [i] = prefix[i-1] + a[i];
    }
    if(l==0){
        return prefix[r];
    }
    return prefix[r]-prefix[l-1];
}
int SubArraySum(vector<int>& a,int k){
    unordered_map<int,int> mp;
    mp[0] = 1;
    int sum=0;
    int count=0;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        if(mp.find(sum-k)!= mp.end()){
            count += mp[sum-k];
        }
        mp[sum]++;
    }
    return count;
}

vector<int> continousSubArray(vector<int>& a,int k){
    unordered_map<int,int> mp;
    mp[0] = -1;
    int sum=0;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        int rem = sum%k;
        if(rem <0) rem +=k;
        if(mp.find(rem)!=mp.end()){
            if(i-mp[rem]>=2){
                return {mp[rem]+1,i};
            }
        }
        else{
            mp[rem] = i;
        }

    }
    return {-1};
}
int maxSizeSubArr(vector<int>&a,int k){
    unordered_map<int,int> mp;
    mp[0] = -1;
    int maxLength = 0;
    int sum =0;
    for(int i=0;i<a.size();i++){
        sum+= a[i];
        if(mp.find(sum-k)!=mp.end()){
            maxLength = max(maxLength,i-mp[sum-k]);
        }
        if(mp.find(sum)==mp.end()){
            mp[sum] = i;

        }
    }
    return maxLength;
}
int main(){
    vector<int> a = {1, -1, 5, -2, 3};
    cout<< maxSizeSubArr(a,3);
    
    
}