#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int BurstBallons(vector<vector<int>>& a){
    int n = a.size();
    if(n==0) return 0;
    sort(a.begin(),a.end(),[](const vector<int>&a,const vector<int>& b){
        return a[1]<b[1];
    });
    int count =1;
    int prev = a[0][1];
    for(int i=1;i<a.size();i++){
        if(a[i][0]>prev){
            count++;
            prev = a[i][1];
        }
    }
    return count;
}
int main(){
    vector<vector<int>> a = {{1,2},{3,4},{5,6},{7,8}};
    cout<<BurstBallons(a);
}