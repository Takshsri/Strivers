#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int CountSubArr(vector<int>& a,int k){
    unordered_map<int,int> prefix;
    prefix[0] = 1;
    int count =0;
    int sum =0;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        int rem = sum %k;
        if(rem<0) rem +=k;
        if(prefix.find(rem)!=prefix.end()){
            count += prefix[rem];
        }
        prefix[rem]++;
    }
    return count;
}
int main(){
    vector<int> arr = {4,5,0,-2,-3,1};
    cout<<CountSubArr(arr,5);
}