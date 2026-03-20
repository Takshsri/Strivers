#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int SubArr(vector<int>& a,int k){
    unordered_map<int,int> prefix;
    int count=0;
    int currSum = 0;
    prefix[0]=1;
    for(int i : a){
        currSum+=i;
        int rem = currSum % k;
        if(rem<0) rem+=k;
        if(prefix.find(rem)!=prefix.end()){
            count+=prefix[rem];
        }
        prefix[rem]++;

    }
    return count;
}
int main(){
    vector<int> a = {4,5,0,-2,-3,1};
    cout<<"Count of SubArrays with Sum Divisible by K:"<<SubArr(a,5);

}