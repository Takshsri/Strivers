#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& a,int low,int high,int mid){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(a[left]<=a[right]){
            temp.push_back(a[left++]);
            
        }
        else{
            temp.push_back(a[right++]);
           
        }
    }

    while(left <= mid){
        temp.push_back(a[left++]);
        
    }
    while(right <= high){
        temp.push_back(a[right++]);
       
    }
    for(int i=0;i<temp.size();i++){
        a[low+i] = temp[i];
    }
}
void  mergeSort(vector<int>& a,int l,int r){
    if(l>=r) return;

    int mid = l +(r-l)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);

    merge(a,l,r,mid);

}


int main(){
    vector<int> a = {45,2,34,1,67,7,5,4};
    mergeSort(a,0,7);
    for(int i : a){
        cout<<i<<" ";
    }
} 