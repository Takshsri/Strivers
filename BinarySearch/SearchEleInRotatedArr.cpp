#include<iostream>
#include<vector>
using namespace std;
int Search(vector<int>& a,int k){
    int l =0;
    int r = a.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(a[mid]==k){
            return mid;
        }
        else if(a[mid]>k){
            if(a[mid]<a[l])r = mid;
            else l = mid+1;
        }
        else if(a[mid]<k){
            if(a[mid]>a[l]) l = mid+1;
            else r = mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> a = {4,5,1,2,3};
    cout<<Search(a,5);
}