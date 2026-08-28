#include<iostream>
#include<vector>
using namespace std;
int LastOccur(vector<int>& a,int k){
    int l =0;
    int r = a.size()-1;
    int res = -1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(a[mid]==k){
            res = mid;
            l = mid+1;
        }
        else if(a[mid]>k){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return res;
}
int main(){
    vector<int> a = {1,2,2,2,2,3,4};
    int k = 2;
    cout<<LastOccur(a,k);
}