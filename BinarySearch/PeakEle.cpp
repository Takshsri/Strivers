#include<iostream>
#include<vector>
using namespace std;
int Peak(vector<int>& a){
    int l = 0;
    int r = a.size()-1;
    while(l<r){
        int mid = l+(r-l)/2;
        if(a[mid]>a[mid+1]){
            r=mid;
        }else{
            l = mid+1;
        }
    }
    return a[l];
}
int main(){
    vector<int> a = {1,2,1};
    cout<<Peak(a);
}