#include<iostream>
#include<vector>
using namespace std;
int MinSubArr(vector<int>& a,int k){
    int mini = INT_MAX;
    int st=0,sum=0;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        while(sum>=k){
            mini = min(mini,i-st+1);
            sum -= a[st++];
        }
    }
    return (mini == INT_MAX)?0: mini;
}
int main(){
    vector<int> a = {1,2,3,4,5};
    cout<<MinSubArr(a,3);
}