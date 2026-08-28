#include<iostream>
#include<vector>
using namespace std;
int Floor(vector<int>& a, int k){
    int l = 0;
    int r = a.size()-1;
    int floor = -1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(a[mid]<k){
            floor = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return a[floor];
}
int main(){
    vector<int>  a = {1,2,4,5,6};
    int k = 7;
    cout<<Floor(a,k);
}