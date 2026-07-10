#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int BinarySum(vector<int>& a,int k){
    unordered_map<int,int> prefix;
    prefix[0] = 1;
    int sum =0;
    int count =0;
    for(int i : a){
        sum += i;
        if(prefix.find(sum-k)!=prefix.end()){
            count+= prefix[sum-k];
        }
        prefix[sum]++;
    }
    return count;
}
int main(){
    vector<int> arr = {1,0,1,0,1};
    cout<<BinarySum(arr,2);
}