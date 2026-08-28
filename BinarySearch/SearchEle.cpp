#include<iostream>
#include<vector>
using namespace std;
int  Search(vector<int>& a,int k){
    int l =0;
    int r = a.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(a[mid]==k){
            return mid;
        }
        else if(a[mid]>k){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}
int main(){
    vector<int> a = {1,3,5,7,9,11};
    int k = 7;
    cout<<Search(a,k);
}