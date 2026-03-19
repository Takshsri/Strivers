#include<iostream>
#include<vector>
#include<map>
using namespace std;
//bruteForce Approach 
//it leads to O(n^3) because of i,j,k looops
int SubArray(vector<int>& a,int k){
    int len=0;
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum =0;
            for(int k=i;k<=j;k++){sum+=a[k];}
            if(sum == k){
                len = max(len,j-i+1);
            }

        }

    }
    return len;
}
//better Solution 
//Hashing
//only for positives 
int SubArrayHash(vector<int>& a,int k){
    long long sum = 0;
    int maxLen = 0;
    map<long long,int >preMap;
    for(int i=0;i<a.size();i++){
        sum +=a[i];
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }
        int rem = sum-k;
        if(preMap.find(rem)!=preMap.end()){
            int len = i-preMap[rem];
            maxLen = max(maxLen,len);
        }
        if(preMap.find(sum) == preMap.end()){
            preMap[sum] = i;
        }
    }
    return maxLen;


}


//Optimal Approach 

int SubArray2Pointer(vector<int>& a,int k){
    int left =0;
    int right =0;
    int maxLen = 0;
    int n = a.size();
    long long sum = a[0];
    while(right < n){
        while(left<=right && sum >k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen,right-left+1);
        }
        right++;
        if(right <n) sum += a[right];

    }
    return maxLen;
}
int main(){
    vector<int> a = {1,2,3,1,1,1,3,2,1,4,3};
    cout<<SubArray2Pointer(a,3);
}