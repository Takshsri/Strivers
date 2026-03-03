#include<iostream>
#include<vector>
using namespace std;
int SmallestEle(vector<int>& a){
    if(a.empty()) return 0;
    int mini = INT_MAX;
    if(a.size() == 1) return mini;
    
    for(int i=1;i<a.size();i++){
        if(a[i]<mini){
            mini = a[i];
        }
    }
    return mini;
}
int main(){
    vector<int> a = {4,5,6,7,23,4};
    cout<<SmallestEle(a);
}