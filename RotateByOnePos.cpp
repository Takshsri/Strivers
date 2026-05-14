#include<iostream>
#include<vector>
using namespace std;
void Reverse(vector<int>&a ,int l,int r){
    while(l<r){
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
    }
}
void Rotate(vector<int>& a){
    int n = a.size();
    if(n==0) return ;
    int d = 1;
    d = d%n;
    Reverse(a,0,n-1);
    Reverse(a,0,d-1);
    Reverse(a,d,n-1);
}
// Left Rotate Array by D positions
void LeftRotate(vector<int>& a,int k){
    int n = a.size();
    k = k%n;
    Reverse(a,0,k-1);
    Reverse(a,k,n-1);
    Reverse(a,0,n-1);
}
int main(){
    vector<int> a = {1,2,3,4,5,6};
    LeftRotate(a,2);
    for(int i : a){
        cout<<i<<" ";
    }
}