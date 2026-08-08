#include<iostream>
#include<vector>
using namespace std;

int LongestSubArr(vector<int>&a,int k){
    int sum =0;
    int longest=INT_MIN;
    int st =0;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        while(sum>k && st<=i){
            
            sum -= a[st++];
        }
        //only update if current window is valid
        if(sum <=k){
            longest = max(longest,i-st+1);
        }
    }
    return (longest == INT_MIN)?-1:longest;
}


int main(){
    vector<int> arr = {2,3,1,2,4,3};
    cout<<LongestSubArr(arr,7);
}