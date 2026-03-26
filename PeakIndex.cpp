#include<iostream>
#include<vector>
using namespace std;
int Peak(vector<int>& a){
    int l =0;
    int r = a.size()-1;
    while(l<=r){
        int mid = l +(r-l)/2;
        if(a[mid-1]<a[mid] && a[mid]>a[mid+1]){
            return mid;
        }
        else if(a[mid-1]<a[mid]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {0,1,2,5,3,2};
    cout<<"Peak Index in a Mounatin Array is :"<<Peak(arr)<<endl;
    cout<<"Peak Element is :"<<arr[Peak(arr)]<<endl;
}