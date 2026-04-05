#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> Leader(vector<int>& a){
    int n = a.size();
    if(n==1)return a;
    vector<int> res;
    res.push_back(a[n-1]);
    int max = a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]>max){
            max = a[i];
            res.push_back(max);
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
//same as this Leetcode 1299 question if
//Array is 17,18,5,4,6,1
//Output 18,6,6,6,1,-1
vector<int> LeaderShip(vector<int>& a){
    int n = a.size();
    int maxi = -1;
    for(int i= n-1;i>=0;i--){
        int temp = a[i];
        a[i]=maxi;
        maxi = max(maxi,temp);
    }
    return a;
}
int main(){
    vector<int> a = {17,18,5,4,6,1};
    vector<int> res = LeaderShip(a);
    for(int i : res){
        cout<<i<<" ";
    }
}