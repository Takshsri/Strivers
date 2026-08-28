#include<iostream>
#include<vector>
using namespace std;
int Ceil(vector<int>& a,int k){
     int l =0;
     int r = a.size()-1;
     int ceil = -1;
     while(l<=r){
        int mid = l+(r-l)/2;
        if(a[mid]>k){
            ceil = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
     }
     return a[ceil];
}
int main(){
    vector<int> a = {1,2,3,4,5};
    int k = 4;
    cout<<Ceil(a,k);
}