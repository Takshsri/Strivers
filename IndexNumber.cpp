#include<iostream>
#include<vector>
using namespace std;
//O(n) time complexity and O(1) space complexity
int Index(vector<int>& a){
    int n = a.size();
    for(int i=0;i<n;i++){
        if(a[i]==i){
            return i;
        }
    }
    return -1;
}

//O(log n)  time complexity and O(1) space complexity
int IndexBinary(vector<int>& a){
    int l=0;
    int r = a.size()-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid]==mid){
            return mid;
        }
        else if(a[mid]<mid){
            l= mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}

int main(){
     vector<int> arr = {1,1,3};
     if(IndexBinary(arr)!=-1){
        cout<<"Index Number is :"<<IndexBinary(arr)<<endl;
     }
     else{ 
        cout<<"No Index Number Found"<<endl;
     }
     
}