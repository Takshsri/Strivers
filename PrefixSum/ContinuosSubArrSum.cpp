#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> CountSubArr(vector<int>& a,int k){
    unordered_map<int,int> prefix;
    prefix[0]=-1;
    int sum =0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        int rem = sum%k;
        if(rem <0) rem+=k;
        if(prefix.find(rem)!=prefix.end()){
            if(i-prefix[rem]>=2){
                return {prefix[rem]+1,i};
            }
        }
        else{
        prefix[rem]=i;
        }
    }
    return {-1};
}
int main(){
    vector<int> a = {25,2,7,8};
    vector<int> res = CountSubArr(a,6);
    for(int i : res){
        cout<<i<<" ";
    }
}