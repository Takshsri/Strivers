#include<iostream>
#include<vector>
using namespace std;
int FirstOccur(vector<int>& a,int k){
    int l =0;
    int r = a.size()-1;
    int res = -1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(a[mid]==k){
            res = mid;
            r = mid-1;
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
int Count(vector<int>& a,int k){
    return (LastOccur(a,k) - FirstOccur(a,k)) +1;
}
int main(){
    vector<int> a  = {1,2,2,3,5};
    int k = 2;
    cout<<Count(a,k)<<endl;
 
}